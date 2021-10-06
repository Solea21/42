/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakorchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 17:50:49 by nakorchi          #+#    #+#             */
/*   Updated: 2018/02/02 10:26:03 by nakorchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*s1b;
	unsigned char	*s2b;

	s1b = (unsigned char*)s1;
	s2b = (unsigned char*)s2;
	i = 0;
	while (s1b[i] != '\0' && s1b[i] == s2b[i])
		i++;
	return (s1b[i] - s2b[i]);
}
