/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechapus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:14:31 by lechapus          #+#    #+#             */
/*   Updated: 2019/09/17 19:14:45 by lechapus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = (char *)s;
	if (str && f)
	{
		while (str[i] != '\0')
		{
			(*f)(i, &str[i]);
			i++;
		}
	}
}
