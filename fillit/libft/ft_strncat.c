/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakorchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 17:41:18 by nakorchi          #+#    #+#             */
/*   Updated: 2018/02/03 02:08:33 by nakorchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, int n)
{
	int	i;
	int	lend;
	int	lens;

	i = 0;
	lend = ft_strlen(dest);
	lens = ft_strlen(src);
	while (i < n && i < lens)
	{
		dest[lend] = src[i];
		lend++;
		i++;
	}
	dest[lend] = '\0';
	return (dest);
}
