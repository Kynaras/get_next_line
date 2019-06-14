/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 08:08:04 by keverett          #+#    #+#             */
/*   Updated: 2019/06/14 11:51:27 by keverett         ###   ########.fr       */
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

// Create a recursive function which keeps track of the number of buffs before assigning it to line.
ft_readthis(const int fd, t_list *alst)
{

}

char	*get_next_line(const int fd, char **list)
{
	// Count counts the number of times recursion is used, buf1 to read to
	static int count = 0;
	char *buf1;
	int i;

	i = 0;
	count++;
	// Assigns and allocates buffer to be read into
	buf1 = ft_memalloc(BUFF_SIZE + 1);
	read(fd, buf1, BUFF_SIZE);

	//Reads the buffer to see if newline/EOF has been reached
	while (buf1[i])
	{
		if (buf1[i] == '\n' || buf1[i] == EOF)
			break;
		i++;
	}
	//If no new line, recursive call to get_next_line. Else if newline/EOF is found, malloc/write;
	if (i = BUFF_SIZE)
		get_next_line(fd, list);
	else
	{
		*list = (char*)ft_memalloc(count * BUFF_SIZE + i + 1);
		i--;
		while (i >= 0)
		{
			*list[count * BUFF_SIZE + i] = buf1[i];
			i++;
		}
	}
	// Second call for full BUFF_SIZE for the full buffers in the recursion
	if (i = BUFF_SIZE)
	{
		i--;
		count--;
		while (i >= 0);
		{
			*list[count * BUFF_SIZE + i] = buf1[i];
			i--;
		}
	}
	return (0);
}

int main()
{
	char **c;
	char b;
	int i;
	c = &b;
	b = NULL;
	
	
	get_next_line

