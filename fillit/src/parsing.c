/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechapus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:54:50 by nakorchi          #+#    #+#             */
/*   Updated: 2019/12/13 22:01:02 by lechapus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_bool	check_connexions(char *t)
{
	int		i;
	int		connex;

	i = 0;
	connex = 0;
	while (t && i < 19)
	{
		if (t[i] == '#')
		{
			if ((i != 0 && i != 5 && i != 10 && i != 15) && t[i - 1] == '#')
				connex++;
			if ((i % 5 == 0) && t[i - 5] == '#')
				connex++;
			else if (5 < i && t[i - 5] == '#')
				connex++;
		}
		i++;
	}
	if (connex < 3 || 4 < connex)
		return (FAILURE);
	return (SUCCESS);
}

static t_bool	check_count(char *t)
{
	int		p;
	int		h;
	int		i;

	i = 0;
	p = 0;
	h = 0;
	while (t && i != 21)
	{
		if (t[i] != '#' && t[i] != '.' && t[i] != '\n' && t[i] != '\0')
			return (FAILURE);
		if (t[i] == '#')
			h++;
		if (t[i] == '.')
			p++;
		i++;
	}
	if ((p != 12 || h != 4 || i != 21) || (check_connexions(t) == FAILURE))
		return (FAILURE);
	return (SUCCESS);
}

t_bool			validate_input(t_data *data)
{
	char	*i_cp;
	int		ret;
	int		i;

	i_cp = ft_strdup(data->ipt);
	i = 0;
	ret = 0;
	while (i < data->tmax)
	{
		data->pt = i_cp + i * 21;
		if (check_count((char*)data->pt) == FAILURE)
			return (FAILURE);
		i++;
	}
	free(i_cp);
	return (SUCCESS);
}
