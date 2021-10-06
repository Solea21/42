/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechapus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:19:40 by lechapus          #+#    #+#             */
/*   Updated: 2019/09/17 19:19:48 by lechapus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*dest;
	const char	*srcs;
	size_t		i;
	size_t		len;

	dest = dst;
	srcs = src;
	i = size;
	while (*dest != '\0' && i-- != 0)
		dest++;
	len = dest - dst;
	i = size - len;
	if (i == 0)
		return (len + ft_strlen(srcs));
	while (*srcs)
	{
		if (i != 1)
		{
			*dest++ = *srcs;
			i--;
		}
		srcs++;
	}
	*dest = '\0';
	return (len + (srcs - src));
}
