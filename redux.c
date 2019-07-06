/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redux.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 23:07:13 by keverett          #+#    #+#             */
/*   Updated: 2019/07/06 07:04:49 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

int	ft_ebuf(char **ebuf, char **line, int rd)
{
	char *tmp; 
	if (ft_strlen(*line) && *line && ft_strchr(*line, '\n') + 1)
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

int	ft_reader(char **line, char **ebuf, int fd)
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
	}
	free(buf);
	rd = ft_ebuf(ebuf, line, rd);
	if (rd == 0)
		return (0);
	return (1);
}

int	ft_isebuf(char **ebuf, char **line, int fd)
{
	if (ft_strchr(*ebuf, '\n'))
	{
		*line = ft_strcdup(*ebuf, '\n');
		ft_strcpy(*ebuf, ft_strchr(*ebuf, '\n') + 1);
		return (1);
	}
	else
	{
		*line = ft_memalloc(1);
		ft_join(line, *ebuf);
		free(*ebuf);
		if (ft_reader(line, ebuf, fd) == 0)
			return (0);
		else
			return (1);
	}
	return (3);
}

int get_next_line(int fd, char **line)
{
	static char *ebuf;

	if (!line || fd < 0 || read(fd, NULL, 0) == -1)
		return (-1);
	if(ebuf)
		return(ft_isebuf(&ebuf, line, fd));
	*line = ft_memalloc(1);
	if (ft_reader(line, &ebuf, fd) == 0)
		return 0;
	return (1);
}

/*
int main(void)
{
	char *line;
	int fd;
	int i;
	int rd;
	i = 0;
	fd = open("text.txt", O_RDONLY);
	while((rd = get_next_line(fd, &line)) >= 0 && i < 5)
	{
		i++;
		printf("i == %d\n", i);
		//rd = get_next_line(fd, &line);
		printf("ret == %d\n", rd);
		printf("line == %s|\n", line);
	}
	return (0);
}*/	
