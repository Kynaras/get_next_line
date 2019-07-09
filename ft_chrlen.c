ssize_t	ft_checkline(char *buf, char c)
{
	int i;

	i = 0;
	if (buf[0] == '\0')
		return (-1);
	while (buf[i])
	{
		if (buf[0] == c)
			return (0);
		if (buf[i] == c)
			return (i);
		i++;
	}
	if (i == BUFF_SIZE)
		return (-2);
	else
		return (i);
}

