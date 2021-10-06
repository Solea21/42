/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakorchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 00:41:31 by nakorchi          #+#    #+#             */
/*   Updated: 2019/10/22 19:56:00 by nakorchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		len;
	char	*ret;

	len = ft_strlen(src);
	if (!(ret = ((char *)malloc(sizeof(char) * len + 1))))
		return (NULL);
	ft_strcpy(ret, src);
	return (ret);
}
