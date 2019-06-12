/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 10:05:39 by keverett          #+#    #+#             */
/*   Updated: 2019/06/12 10:21:35 by keverett         ###   ########.fr       */
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

int ft_check(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' || str[i] == EOF)
			return (i);
		i++;
	}
	return (0);
}

char *ft_read(fd, char *a, char *b, char *c)
{
	read(fd, a, BUFF_SIZE);
	a[BUFF_SIZE] == '\0';
	if
}

char	*get_next_line(const int fd, char **list)
{
	int count;
	char *a;
	char *b;
	static char *c;

	a = (char*)ft_memalloc(BUFF_SIZE + 1);
	count = 1;
	read (fd, a, BUFF_SIZE);
	a[BUFF_SIZE] == '\0';
	if(ft_check(a) == 0)
	{
		b = (char*)malloc(BUFF_SIZE * count *  sizeof(char) + 1);
		ft_strncpy(b, a, BUFF_SIZE);
	}
	//ft_memset(a, '\0', BUFF_SIZE);
	*list = a;
	return (return *list);
}

int main()
{
	char **line;

	line = NULL;
	*line = get_next_line(open("test", O_RDONLY), line);
	printf("%s", *line);
}
