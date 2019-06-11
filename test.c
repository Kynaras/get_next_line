/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 13:04:27 by keverett          #+#    #+#             */
/*   Updated: 2019/06/11 14:44:21 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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
	char *c;

	a = (char*)malloc(BUFF_SIZE * sizeof(char) + 1);
	count = 1;

	read (fd, a, BUFF_SIZE);
	a[BUFF_SIZE] == '\0';
	if(ft_check(a) == 0)
	{
		b = (char*)malloc(BUFF_SIZE * count *  sizeof(char) + 1);
		ft_strncpy(b, a, BUFF_SIZE);
		
	}
	ft_memset(a, '\0', BUFF_SIZE);
	return (ytr);
}
