/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechapus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 22:23:40 by lechapus          #+#    #+#             */
/*   Updated: 2021/10/03 22:24:07 by lechapus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	check(char **memory, int ret)
{
	if (!ret)
	{
		free(*memory);
		*memory = 0;
	}
}

int	get_next_line(int fd, char **line)
{
	static char	*memory[256];
	char		*b;
	int			ret;
	int			r;

	ret = (!memory[fd] && (!(memory[fd] = malloc(1)) || (*memory[fd] = 0)));
	r = !(b = malloc(BUFFER_SIZE + 1));
	if (!line || BUFFER_SIZE <= 0 || !(fd + 1) || ret || r)
		return (-1);
	ret = !ft_strcchr(memory[fd], '\n') && (r = read(fd, b, BUFFER_SIZE));
	while (ret > 0)
	{
		b[r] = 0;
		ft_strconcat(&memory[fd], b);
		ret = !ft_strcchr(memory[fd], '\n') && (r = read(fd, b, BUFFER_SIZE));
	}
	*line = ft_getline(memory[fd], '\n');
	ret = ft_strcchr(memory[fd], '\n');
	ft_chrmove(&memory[fd], '\n');
	free(b);
	if (r == -1)
		return (-1);
	check(&memory[fd], ret);
	return (ret);
}
