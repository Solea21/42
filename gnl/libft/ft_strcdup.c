/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechapus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 21:14:05 by lechapus          #+#    #+#             */
/*   Updated: 2019/10/27 21:14:06 by lechapus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcdup(const char *src, int c)
{
	char	*dest;
	int		j;
	int		i;

	j = 0;
	i = 0;
	dest = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	while (src[i] && src[i] != c)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
