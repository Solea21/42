/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_masta.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakorchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 21:31:10 by nakorchi          #+#    #+#             */
/*   Updated: 2019/12/13 21:57:26 by nakorchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			height(char *tet)
{
	int	i;

	i = 0;
	while (tet[i] != '#')
		i++;
	if (10 < i)
		return (2);
	i = 19;
	while (tet[i] != '#')
		i--;
	if (i < 10)
		return (2);
	if (tet[0] == '.' && tet[1] == '.' && tet[2] == '.' && tet[3] == '.')
		return (3);
	if (tet[15] == '.' && tet[16] == '.' && tet[17] == '.' && tet[18] == '.')
		return (3);
	return (4);
}

static int			width(char *tet)
{
	int		mrh;
	int		mlh;
	int		i;
	int		j;

	i = 0;
	j = 0;
	mlh = 4;
	mrh = 1;
	while (i < 19)
	{
		if (j == 5)
			j = 0;
		if (tet[i] == '#')
		{
			if (j < mlh)
				mlh = j;
			if (mrh < j)
				mrh = j;
		}
		j++;
		i++;
	}
	mrh++;
	return (mrh - mlh);
}

static t_bool		super_check(t_data *data)
{
	int		nt;
	int		i;
	int		width_var;
	int		height_var;

	nt = -1;
	i = 0;
	width_var = 0;
	height_var = 0;
	while (++nt < data->tmax)
	{
		width_var = width(data->ipt + nt * 21);
		height_var = height(data->ipt + nt * 21);
		if (data->sq_side < width_var)
		{
			data->sq_side = width_var;
			return (SUCCESS);
		}
		if (data->sq_side < height_var)
		{
			data->sq_side = height_var;
			return (SUCCESS);
		}
	}
	return (FAILURE);
}

static int			ft_sqrt_abso(int nb)
{
	int		i;

	i = 2;
	if (nb == 1)
		return (1);
	if (nb <= 0)
		return (-1);
	while (nb)
	{
		while (i <= nb / i)
		{
			if (i * i == nb)
				return (i);
			i++;
		}
		i = 2;
		nb++;
	}
	return (-1);
}

t_bool				init_values(t_data *data)
{
	if (!data->tmax)
		return (FAILURE);
	data->sq_side = ft_sqrt_abso(data->tmax * 4);
	if (data->sq_side < 4)
		super_check(data);
	if (data->sq_side == 2)
		return (SUCCESS);
	data->area = data->sq_side * data->sq_side;
	if (!data->sq_side)
		return (FAILURE);
	return (SUCCESS);
}
