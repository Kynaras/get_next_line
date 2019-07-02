#include "get_next_line.h"
#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	ft_checkline(char *buf)
{
	int i;

	i = 0;
	while (buf[i])
	{
		if (buf[0] == '\0')
			return (0);
		if (buf[0] == '\n')
			return (-1);
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	if (i == BUFF_SIZE)
		return (-2);
	else
		return (-3);
}

int ft_ebuf(ssize_t fd, t_list *list, char **line)
{
	int size;
	t_list *tmp;
	char *buffer;

	buffer = ft_memalloc(BUFF_SIZE + 1);
	size = 0;
	tmp = list;
	while (tmp != NULL)
	{
		if (tmp->content_size == fd)
		{
			size = ft_checkline(tmp->content);
			if (size == -1) // Might need to include check if there  is *only* a newline char in buf
			{
				*line = ft_memalloc(1);
				ft_strcpy(tmp->content, tmp->content + 1);
				return (-1);
			}
			else if (size == 0)
				return (0);
			else if (size > 0)
			{
				buffer = ft_memalloc(BUFF_SIZE + 1);
				ft_strncpy(buffer, tmp->content, size);
				ft_join(line, buffer);
				free(buffer);
				ft_strcpy(tmp->content, ft_strchr(tmp->content, '\n') + 1);
				return (size);
			}
			else if (size == -3)
			{
				ft_join(line, tmp->content);
				ft_bzero(tmp->content, BUFF_SIZE + 1);
			}	
		}
		tmp = tmp->next;
	}
	return (-4);
}

int	get_next_line(int fd, char **line)
{
	static t_list *list;
	t_list *tmp;
	char* buf;
	int loop;
	ssize_t rd;
	int check;
	char *temp;

	loop = 0;
	buf = ft_memalloc(BUFF_SIZE + 1);
	rd = ft_ebuf(fd, list, line);
	if (rd > 0)
		return (1);
	while (loop == 0)
	{
		ft_bzero(buf, BUFF_SIZE);
		rd = read(fd, buf, BUFF_SIZE);
		if (rd == -1)
			return (-1);
//		if (rd == 0)
//		{
//			list = ft_lstnew(buf, BUFF_SIZE + 1);
//			list->content_size = -5;
//		}
		check = ft_checkline(buf);
		if (check == -2 || check == 0)
		{
			ft_join(line, buf);
		}
		else
		{
			loop = 1;
			if (check > 0)
			{
				temp = ft_strsub(buf, 0, check);
				ft_join(line, temp);
				free(temp);
			}
			if (list == NULL)
			{
				list = ft_lstnew((ft_strchr(buf, '\n') + 1), BUFF_SIZE + 1);
				list->content_size = fd;
			}
			else
			{
				tmp = list;
				while (tmp != NULL)
				{
					if (tmp->content_size == fd)
					{
						ft_bzero(tmp->content, BUFF_SIZE);
						ft_strcpy(tmp->content, ft_strchr(buf, '\n') + 1);
						break;
					}
					else
						tmp = tmp->next;
				}
				if (tmp == NULL)
				{
					ft_lstadd(&list, ft_lstnew((ft_strchr(buf, '\n') + 1), BUFF_SIZE + 1));
					list->content_size = fd;
				}
			}
		}
	}
	return (1);
}
int main()
{
	char *line = NULL;
	int fd = open("test", O_RDONLY);
	int fd1 = open("test1", O_RDONLY);
	int fd2 = open("test2", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);
	line = NULL;
	get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);
	line = NULL;
	get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);
	line = NULL;
	get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);
	line = NULL;
	get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);

	return (0);
}
