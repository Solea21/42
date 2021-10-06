/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechapus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:39:42 by lechapus          #+#    #+#             */
/*   Updated: 2019/09/17 19:39:51 by lechapus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen((char *)s);
	while (i < (int)len)
	{
		i++;
		s++;
	}
	while (i >= 0)
	{
		if ((char)s[0] == (char)c)
			return ((char *)s);
		s--;
		i--;
	}
	return (NULL);
}
