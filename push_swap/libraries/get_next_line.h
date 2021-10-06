/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechapus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 22:24:25 by lechapus          #+#    #+#             */
/*   Updated: 2021/10/03 22:24:38 by lechapus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

int		ft_strcchr(char *src, int c);
size_t	ft_nstrlen(char *src, int c);
char	*ft_strconcat(char **dst, char *str);
char	*ft_getline(char *src, int c);
char	*ft_chrmove(char **dst, int c);
int		get_next_line(int fd, char **line);

#endif
