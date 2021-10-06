/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechapus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:14:06 by lechapus          #+#    #+#             */
/*   Updated: 2019/09/17 18:14:14 by lechapus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	if (!dest && !src)
		return (NULL);
	if (src >= dest)
		return (ft_memcpy(dest, src, len));
	while (len > 0)
	{
		len--;
		((unsigned char *)dest)[len] = ((unsigned char *)src)[len];
	}
	return ((unsigned char *)dest);
}
