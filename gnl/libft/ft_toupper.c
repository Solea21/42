/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechapus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:45:48 by lechapus          #+#    #+#             */
/*   Updated: 2019/09/17 19:45:53 by lechapus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include "libft.h"

int		ft_toupper(int c)
{
	while (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
