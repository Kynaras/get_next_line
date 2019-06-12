/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 08:08:04 by keverett          #+#    #+#             */
/*   Updated: 2019/06/12 16:02:48 by keverett         ###   ########.fr       */
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

}

char	*get_next_line(const int fd, char **list)
{
	int i;
	char *buf1;
	
	// Assigns and allocates buffer to be read into
	buf1 = ft_memalloc(BUFF_SIZE + 1);
	read(fd, buf1, BUFF_SIZE);

	//Reads the buffer to see if newline/EOF has been reached
	while (buf1[i] != '\n' || buf1[i] != EOF)
		i++;
	if (i = BUFF_SIZE)





	return (ytr);
}

