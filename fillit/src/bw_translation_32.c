/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bw_translation_32.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakorchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 08:06:14 by nakorchi          #+#    #+#             */
/*   Updated: 2019/12/13 22:41:10 by nakorchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		alignement(t_data *data, int nt)
{
	left_col_mask(data);
	top_line_mask(data);
	while (!(and_bf(data->top_line, data->t_ar[nt])))
		bm_top_shift(data->t_ar[nt], data->sq_side);
	while (!(and_bf(data->left_col, data->t_ar[nt])))
		bm_left_shift(data->t_ar[nt]);
}

void		get_bw_val(t_data *data, char *n_tet, int sq_side, int nt)
{
	t_sos	s;

	ft_bzero(&s, sizeof(t_sos));
	s.i_s = -1;
	while (s.i_s++ < 19 || s.tiles < 4)
	{
		if (n_tet[s.i_s] == '.')
		{
			s.i_bf++;
			bm_left_shift(data->t_ar[nt]);
		}
		if (n_tet[s.i_s] == '#')
		{
			s.tiles++;
			bm_left_shift(data->t_ar[nt]);
			data->t_ar[nt][5] |= 1;
			s.i_bf++;
		}
		if (n_tet[s.i_s] == '\n' && 4 < sq_side)
		{
			s.i_bf += sq_side - 4;
			n_shift(data->t_ar[nt], 'l', sq_side - 4, sq_side);
		}
	}
	n_shift(data->t_ar[nt], 'l', 192 - s.i_bf, sq_side);
}

t_bool		init_bw_array(t_data *data)
{
	int		i;
	int		nt;

	i = 0;
	nt = 0;
	while (i < data->tmax)
	{
		ft_bzero(data->t_ar[i], 24);
		i++;
	}
	i = 0;
	ft_bzero(data->solve_map, 24);
	right_col_mask(data);
	left_col_mask(data);
	top_line_mask(data);
	bottom_line_mask(data);
	while (nt < data->tmax)
	{
		data->pt = data->ipt + nt * 21;
		get_bw_val(data, (char*)data->pt, data->sq_side, nt);
		alignement(data, nt);
		nt++;
	}
	return (SUCCESS);
}
