/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechapus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:39:22 by lechapus          #+#    #+#             */
/*   Updated: 2019/10/27 20:39:38 by lechapus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			joker(char *buf, int choice, t_gnl **file, int fd)
{
	int		i;
	t_gnl	*tmp;

	if (choice == 1)
	{
		i = 0;
		while (buf[i] && buf[i] != '\n')
			i++;
		if (buf[i] == '\n')
			return (i + 1);
		else
			return (0);
	}
	else
	{
		tmp = malloc(sizeof(t_gnl));
		tmp->fd = fd;
		tmp->index = 0;
		tmp->end = 0;
		tmp->content = "\0";
		tmp->next = *file;
		*file = tmp;
	}
	return (0);
}

static t_read		getbuf(int fd, char *buf, char *str, char *f)
{
	t_read	tmp;

	tmp.end = 1;
	if (read(fd, buf, BUFF_SIZE) > 0)
		if (joker(buf, 1, NULL, 0) && (tmp.str = ft_strjoin(str, buf)))
		{
			ft_strcmp(f, "\0") != 0 ? free(f) : 0;
			free(buf);
			return (tmp);
		}
		else
		{
			tmp.str = ft_strjoin(str, buf);
			ft_strcmp(str, "\0") != 0 ? free(str) : 0;
			f = tmp.str;
			free(buf);
			return (getbuf(fd, ft_strnew(BUFF_SIZE + 1), tmp.str, f));
		}
	else
	{
		free(buf);
		tmp.end = -1;
		tmp.str = str;
		return (tmp);
	}
}

static int			last_iter(int fd, char *str, t_gnl *tmp_file, char **line)
{
	t_read		tmp;

	tmp = getbuf(fd, ft_strnew(BUFF_SIZE + 1), "\0", "\0");
	if (tmp.end == -1 && ft_strlen(str) > 0)
	{
		tmp_file->content = str;
		str = ft_strjoin(str, tmp.str);
		free(tmp_file->content);
		*line = ft_strcdup(str, '\n');
		tmp_file->end = -1;
		free(str);
	}
	else if (tmp.end == -1 && ft_strlen(str) == 0)
		return (0);
	else
	{
		tmp_file->content = str;
		str = ft_strjoin(str, tmp.str);
		free(tmp_file->content);
		*line = ft_strcdup(str, '\n');
		tmp_file->content = ft_strdup(&str[ft_strlen(*line) + 1]);
		free(str);
	}
	return (1);
}

static int			get_line(int fd, char *str, t_gnl *tmp_file, char **line)
{
	t_read		tmp;

	if (tmp_file->end == 0)
	{
		tmp = getbuf(fd, ft_strnew(BUFF_SIZE + 1), "\0", "\0");
		str = ft_strjoin(tmp_file->content, tmp.str);
		free(tmp.str);
		tmp_file->content = str;
		tmp_file->end = 1;
	}
	if (tmp_file->end == 1)
	{
		str = tmp_file->content;
		if (joker(str, 1, NULL, 0))
		{
			*line = ft_strcdup(str, '\n');
			tmp_file->content = ft_strdup(&str[joker(str, 1, NULL, 0)]);
			free(str);
		}
		else
			return (last_iter(fd, str, tmp_file, line));
	}
	else
		return (0);
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_gnl	*file;
	t_gnl			*tmp_file;
	char			*str;

	str = NULL;
	if (fd < 0 || !line || read(fd, buf, 0) < 0 || BUFF_SIZE < 0)
		return (-1);
	tmp_file = file;
	while (tmp_file)
	{
		if (fd == tmp_file->fd)
			return (get_line(fd, str, tmp_file, line));
		else
			tmp_file = tmp_file->next;
	}
	if (!tmp_file)
	{
		joker(buf, 0, &file, fd);
		tmp_file = file;
		return (get_line(fd, str, tmp_file, line));
	}
	return (1);
}
