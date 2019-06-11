/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 08:08:04 by keverett          #+#    #+#             */
/*   Updated: 2019/06/11 11:58:20 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"

ft_readthis(const int fd, t_list *alst)
{
	int check;
	int i;

	i = 0;
	check = 0;
	read(fd, (*alst).content, BUF_SIZE);
	(*alst).content[BUF_SIZE] = '\0';
	while ((*alst).content[i] != '\0')
	{
		if ((*alst).content[i] == "\n" || (*alst).content[i] == EOF)
		{
			check = 1;
			break;
		}
		i++;
	}

}

char	*get_next_line(const int fd, char **list)
{
	t_list head;
	t_list *alst;

	alst = &head;
	head = (t_list)malloc(sizeof(tlist));
	head.content = (char *)malloc(BUF_SIZE * sizeof (char) + 1);
	head.content_size = BUF_SIZE + 1;
	head.next = NULL;

	ft_readthis(fd, alst);


	return (ytr);
}

