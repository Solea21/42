/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakorchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 10:17:09 by nakorchi          #+#    #+#             */
/*   Updated: 2018/02/03 06:48:43 by nakorchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_lines(char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (s[i] != '\0')
	{
		while (s[i] != c && s[i] != '\0')
			i++;
		if (s[i] == c)
			j++;
		i++;
	}
	return (j);
}

static char	*ft_lines(char const *s, char c)
{
	int		i;
	char	*line;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	if (!(line = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ft_strncpy(line, s, i);
	line[i] = '\0';
	return (line);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**final;

	if (!s || !c)
		return (NULL);
	i = ft_num_lines(s, c);
	j = 0;
	if (!(final = (char**)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			final[j] = ft_lines(s + i, c);
			while (s[i] != c && s[i])
				i++;
			j++;
		}
		if (s[i] == c)
			i++;
	}
	final[j] = NULL;
	return (final);
}
