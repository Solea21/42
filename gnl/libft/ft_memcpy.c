/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechapus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:10:20 by lechapus          #+#    #+#             */
/*   Updated: 2019/09/17 18:10:28 by lechapus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t		i;
	char		*dst;
	const char	*srcs;

	i = 0;
	dst = (char *)dest;
	srcs = (char *)src;
	while (i < len)
	{
		dst[i] = srcs[i];
		i++;
	}
	return (dst);
}
