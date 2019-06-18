/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 08:27:28 by keverett          #+#    #+#             */
/*   Updated: 2019/06/18 16:16:52 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	st_counter(b_list *link)

int	get_next_line(int fd, char **line)
{
	static t_list **alst;
	char *buf;
	int i;
	int nextline;
	int count;

	nextline = 1;
	i = 0;
	buf = ft_memalloc(BUFF_SIZE + 1);
	alst = malloc(sizeof(t_list);

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
		ft_lstadd
	
	


