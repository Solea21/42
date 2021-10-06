/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakorchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 02:07:00 by nakorchi          #+#    #+#             */
/*   Updated: 2019/12/13 22:29:00 by nakorchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;

	if (!src || !dst || !n)
		return (NULL);
	d = (char*)dst;
	s = (char*)src;
	while (0 < n)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dst);
}
