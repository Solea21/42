/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakorchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 19:29:45 by nakorchi          #+#    #+#             */
/*   Updated: 2018/02/02 10:21:13 by nakorchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	n;
	size_t	l;
	char	*ret;

	i = 0;
	if (!s)
		return (NULL);
	n = ft_strlen(s) - 1;
	if (ft_strlen(s) == 0)
		return ((char *)s);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		i++;
		if (s[i] == '\0')
			return (ft_strnew(0));
	}
	while (s[n] == ' ' || s[n] == '\n' || s[n] == '\t')
		n--;
	l = n - i + 1;
	if (!(ret = (char *)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	ft_strncpy(ret, &s[i], l);
	ret[l] = '\0';
	return (ret);
}
