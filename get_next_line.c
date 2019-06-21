/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 08:27:28 by keverett          #+#    #+#             */
/*   Updated: 2019/06/21 12:03:06 by keverett         ###   ########.fr       */
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
		cast = (*ptr).content;
		while (cast[i] != '\0')
		{
			if (cast[i] == '\n')
				return (count);
			i++;
			count++;
		}
		i = 0;
		ptr = (*ptr).next;
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
void ft_recurse(int fd, char **line, t_list **alst)
{
	char *buf;
	int i;
	int count;

	count = 0;
	i = 0;
	buf = ft_memalloc(BUFF_SIZE + 1);
	read(fd, buf, BUFF_SIZE);
	while (buf[i])
	{
		if (buf[i] == '\n')
			break;
		else
			i++;
	}
	if(i == BUFF_SIZE)
		ft_recurse(fd, line, alst);
	else
	{
		alst = malloc(sizeof(t_list*));
		*alst = ft_lstnew(buf, BUFF_SIZE + 1);
//		ebuf = ft_lstnew(ft_strsub(buf, i + 1, BUFF_SIZE - i - 1), BUFF_SIZE
//				- i - 1);
//		ft_putstr(ebuf->content);
	}
	if (i == BUFF_SIZE)
		ft_lstadd(alst, ft_lstnew(buf, BUFF_SIZE + 1));
	count = ft_count(alst);
	*line = ft_memalloc(count + 1);
	ft_lstcpy(alst, line);
	ft_delist(alst);
}
int	get_next_line(int fd, char **line)
{
	t_list **alst;
	static t_list *ebuf;
	t_list *ptr;
	char *buf;
	int i;
	int count;

	//if (*line != NULL)
	//	free(*line);

	i = 0;

	ft_recurse(fd, line, alst);
/*	buf = ft_memalloc(BUFF_SIZE + 1);
	read(fd, buf, BUFF_SIZE);
	while (buf[i])
	{
		if (buf[i] == '\n')
			break;
		else
			i++;
	}
	if(i == BUFF_SIZE)
		get_next_line(fd, line);
	else
	{
		alst = malloc(sizeof(t_list*));
		*alst = ft_lstnew(buf, BUFF_SIZE + 1);
//		ebuf = ft_lstnew(ft_strsub(buf, i + 1, BUFF_SIZE - i - 1), BUFF_SIZE
//				- i - 1);
//		ft_putstr(ebuf->content);
	}
	if (i == BUFF_SIZE)
	{
		ft_lstadd(alst, ft_lstnew(buf, BUFF_SIZE + 1));
		free(buf);
	}
	count = ft_count(alst);
	*line = ft_memalloc(count + 1);
	ft_lstcpy(alst, line);
	ft_delist(alst); */
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


