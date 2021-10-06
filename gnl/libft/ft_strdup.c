/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechapus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:07:14 by lechapus          #+#    #+#             */
/*   Updated: 2019/09/17 19:07:21 by lechapus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*str;
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (s1[i] != '\0')
		i++;
	str = (char*)malloc(sizeof(*str) * (i + 1));
	if (str == NULL)
		return (NULL);
	while (i > len)
	{
		str[len] = s1[len];
		len++;
	}
	str[len] = '\0';
	return (str);
}
