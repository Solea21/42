/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakorchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 07:49:45 by nakorchi          #+#    #+#             */
/*   Updated: 2018/02/03 06:47:53 by nakorchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*wow(int n, int len, char *ret)
{
	while (n / 10)
	{
		ret[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	ret[len] = n + '0';
	return (ret);
}

char		*ft_itoa(int n)
{
	int		tmp;
	int		len;
	char	*ret;

	tmp = n;
	len = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	while (tmp /= 10)
		len++;
	tmp = n;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	if (!(ret = ((char *)malloc(sizeof(char) * len + 1))))
		return (NULL);
	ret[len] = '\0';
	if (tmp < 0)
		ret[0] = '-';
	len--;
	return (wow(n, len, ret));
}
