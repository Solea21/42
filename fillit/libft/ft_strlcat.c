/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakorchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 09:19:46 by nakorchi          #+#    #+#             */
/*   Updated: 2018/02/03 06:49:32 by nakorchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	popo;
	size_t	lens;
	size_t	lend;

	popo = 0;
	lend = ft_strlen(dst);
	lens = ft_strlen(src);
	if (size == 0)
		return (lens);
	while (src[popo] != '\0' && (lend + popo) < (size - 1))
	{
		dst[lend + popo] = src[popo];
		++popo;
	}
	dst[lend + popo] = '\0';
	if (lend < size)
		return (lens + lend);
	return (lens + size);
}
