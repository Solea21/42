/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechapus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:11:02 by lechapus          #+#    #+#             */
/*   Updated: 2019/09/17 18:11:07 by lechapus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const unsigned char	*strs;
	size_t				i;

	i = 0;
	strs = str;
	while (n > i)
	{
		if (strs[i] == (unsigned char)c)
			return (char *)(&strs[i]);
		i++;
	}
	return (NULL);
}
