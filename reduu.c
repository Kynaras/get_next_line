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
		if (buf[0] == '\n')
			return (-1);
		if (buf[i] == '\n')
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
	static t_list *list;
	t_list *tmp;
	char *temp;
	char* buf;
	int loop;
	int rd;
	int check;

	list = NULL;
	*line = ft_memalloc(1);
	loop = 0;
	buf = ft_memalloc(BUFF_SIZE + 1);

	while (loop == 0)
	{
		ft_bzero(buf, BUFF_SIZE);
		rd = read(fd, buf, BUFF_SIZE);
		check = ft_checkline(buf);
		/*	if (check == -1)
			{
			loop = 1;
			return(1);
			}*/
		if (check == -2)
		{
			temp = ft_strjoin(*line, buf);
			free(*line);
			*line = ft_strdup(temp);
			free(temp);
		}
		else
		{
			if (check > 0)
			{
				temp = ft_strjoin(*line, ft_strsub(buf, 0, check));
				free(*line);
				*line = ft_strdup(temp);
				free(temp);
			}
			loop = 1;
			if (list == NULL)
			{
				printf("%s", (ft_strchr(buf, '\n') + 1));
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
	printf("%s\n", list->content);
	return (0);
}
int main()
{
	char *line;
	int fd = open("test", O_RDONLY);

	get_next_line(fd, &line);
	printf("%s", line);
	return (0);
}
