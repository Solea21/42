/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechapus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:38:30 by lechapus          #+#    #+#             */
/*   Updated: 2019/09/17 19:38:38 by lechapus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *stack, const char *n, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	while (stack[i] != '\0' && len > i)
	{
		k = 0;
		if (n[k] == '\0')
			return ((char *)stack);
		while (n[k] == stack[i + k] && len > k + i)
		{
			if (n[k + 1] == '\0')
				return (char *)(stack + i);
			k++;
		}
		i++;
	}
	return (0);
}
