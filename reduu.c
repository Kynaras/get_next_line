int	ft_checkline(char **buf)
{
	int i;

	i = 0;
	while (buf[i])
	{
		if (buf[0] == '\n')
			return (-1);
		else if (buf[i] == '\n')
			return (i);
		i++;
	}
	if (i == BUFF_SIZE)
		return (-2);
	else
		return (i);
}

int	get_next_line(int fd, char **line)
{
	static char* buf;
	char *tmp;
	int loop;
	int rd;
	int check;

	*line = ft_memalloc(1);

	buf = ft_memalloc(BUFF_SIZE + 1);

	while (loop == 0);
	{
		rd = read(fd, buf, BUFF_SIZE);
		check = ft_checkline(buf);
		if (check = -1)
		{
			loop = 1;
			return(line);
		}
		else if (check = -2)
		{
			tmp = ft_strjoin(*line, buf);
			free(*line);
			*line = ft_strdup(tmp);
			free(tmp);
		}
		else
		{
			tmp = ft_strjoin(*line, ft_strsub(buf, 0, check));
			free(*line);
			*line = ft_strdup(tmp);
			free(tmp);
			loop = 1;
		}
		return (0);

	}	

int main
