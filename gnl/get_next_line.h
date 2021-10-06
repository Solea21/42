/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechapus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:40:10 by lechapus          #+#    #+#             */
/*   Updated: 2019/10/27 20:40:16 by lechapus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define BUFF_SIZE 42

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_gnl
{
	int				fd;
	int				index;
	int				end;
	char			*content;
	struct s_gnl	*next;
}					t_gnl;

typedef struct
{
	int				end;
	char			*str;
}					t_read;

int					get_next_line(const int fd, char **line);

#endif
