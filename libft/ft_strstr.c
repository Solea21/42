/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechapus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:40:55 by lechapus          #+#    #+#             */
/*   Updated: 2019/09/17 19:41:11 by lechapus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*s1;
	char	*s2;

	if (*needle == 0)
		return ((void *)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			s1 = (void *)haystack + 1;
			s2 = (void *)needle + 1;
			while (*s1 && *s2 && *s1 == *s2)
			{
				++s1;
				++s2;
			}
			if (*s2 == 0)
				return ((void *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
