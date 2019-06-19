/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 08:27:28 by keverett          #+#    #+#             */
/*   Updated: 2019/06/19 09:40:41 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	st_counter(b_list *link)

void ft_count(char **line, t_list **alst)
{
	t_list *ptr;
	int i;
	int count;

	i = 0;
	count = 0;
	ptr = *alst;
	while (ptr != NULL)
	{
		while (ptr.content[i] != '\0')
		{
			if (ptr.content[i] == '\n' || ptr.content == EOF)
				break;
			i++;
			count++;
		}
		i = 0;
	}
	*line = (char*)malloc(sizeof(char) * count + 1);
		
		
int	get_next_line(int fd, char **line)
{
	static t_list **alst;
	t_list *ptr;
	char *buf;
	int i;
	int nextline;
	int count;

	nextline = 1;
	i = 0;
	buf = ft_memalloc(BUFF_SIZE + 1);
	alst = malloc(sizeof(*t_list));

	read(buf, BUFF_SIZE);
	while(buf[i])
	{
		if (buf[i] == '\n' || buf[i] == EOF)
			break;
		else
			i++;
	}
	if(i == BUFF_SIZE)
		get_next_line(fd, line);
	else
		*alst = ft_lstnew(buf, 0);
	if (i == BUFF_SIZE)
		ft_lstadd(t_list **alst, ft_lstnew(buf, 0));


}
int main()
{
	int id;
	id = open("test", O_RDONLY);
	get_next_line(id, 
	



