/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakorchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 02:47:02 by nakorchi          #+#    #+#             */
/*   Updated: 2018/02/02 10:30:10 by nakorchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	void	*tmp;
	size_t	size;

	tmp = ft_memchr(src, c, n);
	if (!tmp)
	{
		ft_memcpy(dst, src, n);
		return (NULL);
	}
	size = tmp - src + 1;
	ft_memcpy(dst, src, size);
	return (dst + size);
}
