/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redux.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 23:07:13 by keverett          #+#    #+#             */
/*   Updated: 2019/07/06 12:57:46 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

int	ft_ebuf(char **ebuf, char **line, int rd)
{
	char *tmp; 
	if (ft_strchr(*line, '\n'))
	{
		tmp = ft_strdup(*line);
		*ebuf = ft_strdup(ft_strchr(*line, '\n') + 1);
		free(*line);
		*line = ft_strcdup(tmp, '\n');
		free(tmp);
		return (1);
	}
	else if (rd == 0)
		return (0);
	return (2);
}

int	ft_reader(char **line, char **ebuf, int fd, size_t *count)
{
	char *buf;
	int loop;
	ssize_t rd;

	rd = 1;
	loop = 0;
	buf = ft_memalloc(BUFF_SIZE + 1);
	while (loop == 0 && rd > 0)
	{
		ft_bzero(buf, BUFF_SIZE);
		rd = read(fd, buf, BUFF_SIZE);
		loop = ft_strclen(buf, '\n');
		ft_join(line, buf);
		printf("Line is %s|", *line);
	}
	free(buf);
	ft_ebuf(ebuf, line, rd);
	if (rd == 0)
	{
		if (*count == 0)
		{
			*count = 1;
			return (1);
		}
		return (0);
	}
	return (1);
}

int	ft_isebuf(char **ebuf, char **line, int fd, size_t *count)
{ 
	if (ft_strchr(*ebuf, '\n'))
	{
		*line = ft_strcdup(*ebuf, '\n'); 
		ft_strcpy(*ebuf, ft_strchr(*ebuf, '\n') + 1);
	   if ((*ebuf)[0] == '\0')
		   free(*ebuf);	   
		return (1);
	}
	else
	{
		*line = ft_memalloc(1);
		ft_join(line, *ebuf);
		free(*ebuf);
		if (ft_reader(line, ebuf, fd, count) == 1)
		{
			return (1);
		}
		else
			return (0);
	}
	return (3);
}

int get_next_line(int fd, char **line)
{
	static char *ebuf;
	static size_t count;

	if (!line || fd < 0 || read(fd, NULL, 0) == -1)
		return (-1);
	printf("%s", ebuf);
	if(ebuf)
	{
		return(ft_isebuf(&ebuf, line, fd, &count));
	}
	*line = ft_memalloc(1);
	if (ft_reader(line, &ebuf, fd, &count) == 0)
		return 0;
	return (1);
}

/*
   int				main(void)
   {
   char		*line;
   int			fd;
   int			ret;
   int			count_lines;
   char		*filename;
   int			errors;

   filename = "gnl7_1.txt";
   fd = open(filename, O_RDONLY);
   if (fd > 2)
   {
   count_lines = 0;
   errors = 0;
   line = NULL;
   while ((ret = get_next_line(fd, &line)) > 0)
   {
   if (count_lines == 0 && strcmp(line, "12345678") != 0)
   errors++;
   count_lines++;
   if (count_lines > 50)
   break ;
   }
   close(fd);
   if (count_lines != 1)
   printf("-> must have returned '1' once instead of %d time(s)\n", count_lines);
   if (errors > 0)
   printf("-> must have read \"12345678\" instead of \"%s\"\n", line);
   if (count_lines == 1 && errors == 0)
   printf("OK\n");
   }
   else
   printf("An error occured while opening file %s\n", filename);
   return (0);
   }*/


int main(void)
{
	char *line;
	int fd;
	int i;
	int rd;
	i = 0;
	fd = open("text.txt", O_RDONLY);
	while((rd = get_next_line(fd, &line)) > 0)
	{
		i++;
		printf("i == %d\n", i);
		//rd = get_next_line(fd, &line);
		printf("ret == %d\n", rd);
		printf("line == %s|\n", line);
	}
	return (0);
}
/*
   int main(void)
   {
   char 	*line;
   int		out;
   int		p[2];
   int		fd;

   fd = 1;
   out = dup(fd);
   pipe(p);

   dup2(p[1], fd);
   write(fd, "aaa\nbbb\nccc\nddd\n", 16);
   dup2(out, fd);
   close(p[1]);
   get_next_line(p[0], &line);
   printf("%s", line);
   }*/
