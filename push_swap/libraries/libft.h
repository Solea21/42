/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechapus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 22:25:58 by lechapus          #+#    #+#             */
/*   Updated: 2021/10/03 22:26:11 by lechapus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int			ft_strcmp(char *s1, char *s2);
void		ft_putstr_fd(const char *s, int fd);
int			ft_atoi(const char *nptr);
long long	ft_atoll(const char *str);
int			count_words(const char *s, char c);
char		**ft_split(char const *s, char c, int nb_words);
char		**free_tab2d(char **tab, int len);
void		*ft_calloc(size_t nmemb, size_t size);
size_t		ft_strlen(const char *s);
int			ft_isdigit(int c);

#endif
