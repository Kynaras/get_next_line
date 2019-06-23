int	ft_linecheck(char **buf)
{
	int i;
	
	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	if (i = BUFF_SIZE)
		return 0;
}

int	get_next_line(int fd, char **line)
{
	char *buf;
	int rd;

	buf = ft_memalloc(BUFF_SIZE + 1);
	rd = 0;


	rd = read(fd, buf, BUFF_SIZE);
	
	if (ft_linecheck(buf) = 0)
	

	if rd = -1
		return (-1);
	
