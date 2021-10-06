/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechapus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:31:23 by lechapus          #+#    #+#             */
/*   Updated: 2019/09/24 18:46:21 by lechapus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void				ft_init(int *i, unsigned long *res, int *sign)
{
	*i = 0;
	*res = 0;
	*sign = 1;
}

static unsigned long	ft_check(unsigned long res, int sign)
{
	if (res > 9223372036854775807 && sign == 1)
		return (-1);
	else if (res > 9223372036854775807 && sign == -1)
		return (0);
	else
		return (res);
}

int						ft_atoi(const char *str)
{
	int				i;
	unsigned long	res;
	int				sign;

	ft_init(&i, &res, &sign);
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 10 + str[i] - '0';
		else
			break ;
		i++;
	}
	res = ft_check(res, sign);
	return (sign * (int)res);
}
