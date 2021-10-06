/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakorchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 02:28:18 by nakorchi          #+#    #+#             */
/*   Updated: 2018/02/03 05:53:43 by nakorchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;

	s = (char*)src;
	d = (char*)dst;
	len--;
	if (src <= dst)
	{
		while (0 <= (int)len)
		{
			*(d + len) = *(s + len);
			len--;
		}
		return (d);
	}
	else
		return (ft_memcpy(dst, src, len + 1));
}
