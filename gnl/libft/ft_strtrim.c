/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechapus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:43:55 by lechapus          #+#    #+#             */
/*   Updated: 2019/09/17 19:44:11 by lechapus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		min;
	int		max;
	int		i;

	if (!s)
		return (NULL);
	min = 0;
	while (s[min] && (s[min] == '\t' || s[min] == '\n' || s[min] == ' '))
		min++;
	max = min;
	while (s[max])
		max++;
	while (s[max - 1] == '\t' || s[max - 1] == '\n' || s[max - 1] == ' ')
		max--;
	str = (char *)malloc(sizeof(*str) * max + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (min < max)
		str[i++] = s[min++];
	str[i] = '\0';
	return (str);
}
