#include "get_next_line.h"
#include "libft/libft.h"

ssize_t	ft_checkline(char *buf)
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
		return (i);
}

ssize_t ft_ebuf(int fd, t_list *list, char **line)
{
	ssize_t size;
	t_list *tmp;
	char *buffer;

	buffer = ft_memalloc(BUFF_SIZE + 1);
	size = 0;
	tmp = list;
	while (tmp != NULL)
	{
		if (tmp->content_size == (unsigned)fd)
		{
			size = ft_checkline(tmp->content);
			if (size == -1)
			{
				*line = ft_memalloc(1);
		//		if (ft_strchr(tmp->content, '\n') == NULL)
		//			ft_bzero(tmp->content, BUFF_SIZE);
		//		else
					ft_strcpy(tmp->content, ft_strchr(tmp->content, '\n') + 1);
				free(buffer);
				return (-1);
			}
			else if (size == 0)
			{
				free(buffer);
				return (0);
			}
			else if (size > 0)
			{
				ft_strncpy(buffer, tmp->content, size);
				ft_join(line, buffer);
				free(buffer);
				if (ft_strchr(tmp->content, '\n') == NULL)
				{
					ft_bzero(tmp->content, BUFF_SIZE);
					return (-2);
				}
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
	free(buffer);
	return (-4);
}

int	get_next_line(int fd, char **line)
{
	static t_list *list;
	t_list *tmp;
	char* buf;
	int loop;
	ssize_t rd;
	ssize_t check;
	char *temp;
	if (!line || fd < 0 || read(fd, NULL, 0) == -1)
		return (-1);
	*line = ft_memalloc(1);
	loop = 0;
	buf = ft_memalloc(BUFF_SIZE + 1);
	check = ft_ebuf(fd, list, line);
	if (check > 0 || check == -1)
	{
		free(buf);
		return (1);
	}
	while (loop == 0)
	{
		ft_bzero(buf, BUFF_SIZE);
		rd = read(fd, buf, BUFF_SIZE);
		if (rd == -1)
		{
			free(buf);
			return (-1);
		}
		if (rd == 0)
		{
			free(buf);
			if (check == -2)
				return (1);
			return (0);
		}
		check = ft_checkline(buf);
		if (check == -2)
		{
			ft_join(line, buf);
		}
		else
		{
			loop = 1;
			if (check > 0 || check == -1)
			{
				if (check > 0)
				{
				temp = ft_strsub(buf, 0, check);
				ft_join(line, temp);
				free(temp);
				}
				if (list == NULL && (char*)ft_strchr(buf, '\n') != NULL)
				{
					list = ft_lstnew(buf, BUFF_SIZE + 1);
					ft_strcpy(list->content, ft_strchr(list->content, '\n') + 1);
					list->content_size = fd;
				}
				else
				{
					tmp = list;
					while (tmp != NULL)
					{
						if (tmp->content_size == (unsigned)fd)
						{
							ft_bzero(tmp->content, BUFF_SIZE);
							ft_strcpy(tmp->content, ft_strchr(buf, '\n') + 1);
							break;
						}
						else
							tmp = tmp->next;
					}
				}
				if (tmp == NULL && ft_strchr(buf, '\n') != NULL)
				{
					ft_lstadd(&list, ft_lstnew(buf, BUFF_SIZE + 1));
					ft_strcpy(list->content, ft_strchr(list->content, '\n') + 1);
					list->content_size = fd;
				}
			}
		}
	}
	free(buf);
	return (1);
}
