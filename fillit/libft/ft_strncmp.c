/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakorchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 17:52:28 by nakorchi          #+#    #+#             */
/*   Updated: 2018/02/03 05:31:50 by nakorchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1b;
	unsigned char	*s2b;

	s1b = (unsigned char*)s1;
	s2b = (unsigned char*)s2;
	i = 0;
	while ((s1b[i] != '\0') && (i < n) && (s1b[i] == s2b[i]))
		i++;
	if (i == n)
		return (0);
	return (s1b[i] - s2b[i]);
}
