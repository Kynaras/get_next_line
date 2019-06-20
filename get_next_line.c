/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 08:27:28 by keverett          #+#    #+#             */
/*   Updated: 2019/06/20 15:48:49 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "get_next_line.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

void ft_delist(t_list **alst)
{
	t_list *ptr;
	t_list *temp;
	ptr = *alst;
	temp = *alst;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		free(temp);
		temp = ptr;
	}
}

int	ft_count(t_list **alst)
{
	t_list *ptr;
	int i;
	int count;
	char *cast;

	i = 0;
	count = 0;
	ptr = *alst;
	while (ptr != NULL)
	{
		cast = ptr->content;
		while (cast[i] != '\0')
		{
			if (cast[i] == '\n')
				return (count);
			i++;
			count++;
		}
		i = 0;
		ptr = ptr->next;
	}
	return (count);
}

void	ft_lstcpy(t_list **alst, char **line)
{
	t_list *ptr;
	int i;
	int j;
	char *cast;
	i = 0;
	j = 0;
	ptr = *alst;

	while (ptr != NULL)
	{
		cast = ptr->content;
		while (cast[i] != '\0')
		{
			(*line)[j] = cast[i];
			i++;
			j++;
		}
		i = 0;
		ptr = ptr->next;
	}
}
int	get_next_line(int fd, char **line)
{
	t_list **alst;
	static t_list *ebuf;
	t_list *ptr;
	char *buf;
	int i;
	int end;
	int nextline;
	int count;

	if (*line != NULL)
		free(*line);

	nextline = 1;
	i = 0;
	end = 0;
	buf = ft_memalloc(BUFF_SIZE + 1);
	alst = malloc(sizeof(t_list*));

	end = read(fd, buf, BUFF_SIZE);
	while (buf[i])
	{
		if (buf[i] == '\n' || end == -1 )
			break;
		else
			i++;
	}
	if(i == BUFF_SIZE)
		get_next_line(fd, line);
	else
	{
		*alst = ft_lstnew(buf, BUFF_SIZE + 1);
		ebuf = ft_lstnew(ft_strsub(buf, i + 2, BUFF_SIZE - i - 1), BUFF_SIZE
				- i - 1);
		ft_putstr(ebuf->content);
	}
	if (i == BUFF_SIZE)
		ft_lstadd(alst, ft_lstnew(buf, BUFF_SIZE + 1));
	count = ft_count(alst);
	*line = (char *)malloc(sizeof(char) * count + 1);
	ft_lstcpy(alst, line);
	ft_delist(alst);
	return(1);

}
int main()
{
	char **line;
	line = (char**)malloc(sizeof(char*));
	*line = (char*)malloc(sizeof(char));
	int id;
	id = open("test", O_RDONLY);
	get_next_line(id, line);
	printf("%s", *line);
}


