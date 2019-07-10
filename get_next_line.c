/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 10:07:26 by keverett          #+#    #+#             */
/*   Updated: 2019/07/10 15:32:01 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

void	ft_lstad(t_list **list, char *buf, int fd)
{
	t_list *tmp;

	tmp = *list;
	while (tmp != NULL)
	{
		if (tmp->content_size == (unsigned)fd && ft_strchr(buf,
					'\0' != ft_strchr(buf, '\n') + 1))
		{
			ft_bzero(tmp->content, BUFF_SIZE);
			ft_strcpy(tmp->content, ft_strchr(buf, '\n') + 1);
			break;
		}
		else
			tmp = tmp->next;
	}
	if (tmp == NULL && ft_strchr(buf, '\n') != NULL && ft_strchr(buf,
				'\0') != ft_strchr(buf, '\n') + 1)
	{
		ft_lstadd(list, ft_lstnew(buf, BUFF_SIZE + 1));
		ft_strcpy((**list).content, ft_strchr((**list).content, '\n') + 1);
		(**list).content_size = fd;
	}
}

void	ft_lstmake(t_list **list, char **line, char *buf, int fd)
{
	int check;
	char *temp;

	check = ft_chrlen(buf, '\n');
	if (check >= 0)
	{
		if (check > 0)
		{
			temp = ft_strsub(buf, 0, check);
			ft_join(line, temp);
			free(temp);
		}
		if (list == NULL && ft_strchr(buf, '\n') != NULL && ft_strchr(buf,
					'\0') != ft_strchr(buf, '\n') + 1)
		{
			*list = ft_lstnew(buf, BUFF_SIZE + 1);
			ft_strcpy((**list).content, ft_strchr((**list).content, '\n') + 1);
			(**list).content_size = fd;
		}
		else
			ft_lstad(list, buf,fd);
	}
}

ssize_t	ft_ebuf(int fd, t_list *list, char **line, char *buf)
{
	ssize_t size;
	t_list *tmp;

	tmp = list;
	while (tmp != NULL)
	{
		if (tmp->content_size == (unsigned)fd)
		{
			if ((size = ft_chrlen(tmp->content, '\n')) == -1)
				return (0);
			if (size == 0 && ft_strcpy(tmp->content, tmp->content + 1))
				return (-1);
			ft_strncpy(buf, tmp->content, size);
			ft_join(line, buf);
			if (ft_strchr(tmp->content, '\n') == NULL)
			{
				ft_bzero(tmp->content, BUFF_SIZE);
				return (-2);
			}
			ft_strcpy(tmp->content, ft_strchr(tmp->content, '\n') + 1);
			return (size);
		}
		tmp = tmp->next;
	}
	return (-4);
}

int		ft_loop(t_list **list, char **line, int check, int fd)
{
	int loop;
	ssize_t rd;
	char *buf;

	buf = ft_memalloc(BUFF_SIZE + 1);
	loop = 0;
	while (loop == 0)
	{
		ft_bzero(buf, BUFF_SIZE);
		if ((rd = read(fd, buf, BUFF_SIZE)) == 0)
		{
			free(buf);
			if (check != 0 && check != -4)
				return (1);
			return (0);
		}
		if ((check = ft_chrlen(buf, '\n')) == BUFF_SIZE)
			ft_join(line, buf);
		else
		{
			loop = 1;
			ft_lstmake(list, line, buf, fd);
		}
	}
	free(buf);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static t_list *list;
	char* buf;
	ssize_t check;

	if (!line || fd < 0 || read(fd, NULL, 0) == -1)
		return (-1);
	*line = ft_memalloc(1);
	buf = ft_memalloc(BUFF_SIZE + 1);
	check = ft_ebuf(fd, list, line, buf);
	if (check > 0 || check == -1)
	{
		free(buf);
		return (1);
	}
	free(buf);	
	return (ft_loop(&list, line, check, fd));
}
