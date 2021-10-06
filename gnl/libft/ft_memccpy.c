/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechapus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:12:54 by lechapus          #+#    #+#             */
/*   Updated: 2019/09/17 18:12:59 by lechapus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char		*dst;
	const char	*srcs;
	size_t		i;

	i = 0;
	dst = (char *)dest;
	srcs = (char *)src;
	while (i < n)
	{
		dst[i] = srcs[i];
		if (srcs[i] == (char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
