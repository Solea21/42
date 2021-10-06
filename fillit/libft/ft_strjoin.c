/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakorchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:57:14 by nakorchi          #+#    #+#             */
/*   Updated: 2018/05/19 16:40:26 by nakorchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*ret;

	if (!s1 || !s2)
		return (NULL);
	len2 = ft_strlen(s2);
	len1 = ft_strlen(s1);
	if (!(ret = (char*)malloc(sizeof(*ret) * (len1 + len2 + 1))))
		return (NULL);
	ft_strcpy(ret, s1);
	ft_strcpy(&ret[len1], s2);
	return (ret);
}
