/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_box_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakorchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 04:31:37 by nakorchi          #+#    #+#             */
/*   Updated: 2019/12/13 22:18:45 by nakorchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		xor_bf(unsigned int *solve_map, unsigned int *mask)
{
	int		i;

	i = 0;
	while (i <= 5)
	{
		solve_map[i] ^= mask[i];
		i++;
	}
}

void		n_shift(unsigned int *bf, char c, int rounds, int sq_side)
{
	while (rounds)
	{
		if (c == 'l')
			bm_left_shift(bf);
		if (c == 'r')
			bm_right_shift(bf);
		if (c == 'b')
			bm_bottom_shift(bf, sq_side);
		if (c == 't')
			bm_top_shift(bf, sq_side);
		rounds--;
	}
}

t_bool		and_bf(unsigned int *bf1, unsigned int *bf2)
{
	int		i;

	i = 0;
	while (i < 6)
	{
		if (bf1[i] & bf2[i])
			return (SUCCESS);
		i++;
	}
	return (FAILURE);
}

int			tet_width(unsigned int *bf, int sq_side, t_data *data)
{
	int		i;
	int		width;

	i = 0;
	width = 0;
	left_col_mask(data);
	if (and_bf(bf, data->left_col))
		width++;
	while (i < sq_side - 1)
	{
		bm_right_shift(data->left_col);
		if (and_bf(bf, data->left_col))
			width++;
		i++;
	}
	left_col_mask(data);
	return (width);
}

t_bool		tet_right_shift(t_data *data, int nt)
{
	int				sq_side;
	int				width;

	sq_side = data->sq_side;
	width = tet_width(data->t_ar[nt], sq_side, data);
	if (and_bf(data->t_ar[nt], data->right_col))
	{
		if (and_bf(data->t_ar[nt], data->bottom_line))
			return (FAILURE);
		n_shift(data->t_ar[nt], 'r', width, data->sq_side);
	}
	else
		bm_right_shift(data->t_ar[nt]);
	return (SUCCESS);
}
