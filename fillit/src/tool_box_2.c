/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_box_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakorchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 01:47:00 by nakorchi          #+#    #+#             */
/*   Updated: 2019/12/13 22:08:43 by nakorchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		right_col_mask(t_data *data)
{
	int		i;

	i = data->sq_side;
	ft_bzero(data->right_col, 24);
	while (i)
	{
		n_shift(data->right_col, 'r', data->sq_side, data->sq_side);
		data->right_col[0] |= 1 << (31 - data->sq_side + 1);
		i--;
	}
}

void		left_col_mask(t_data *data)
{
	int		i;

	i = 0;
	ft_bzero(data->left_col, 24);
	while (i < data->sq_side)
	{
		n_shift(data->left_col, 'r', data->sq_side, data->sq_side);
		data->left_col[0] |= 1 << 31;
		i++;
	}
	data->left_col[0] |= 1 << 31;
}

void		top_line_mask(t_data *data)
{
	int		i;

	i = data->sq_side;
	ft_bzero(data->top_line, 24);
	while (i)
	{
		bm_right_shift(data->top_line);
		data->top_line[0] |= 1 << 31;
		i--;
	}
}

void		bottom_line_mask(t_data *data)
{
	int		sq_side;

	ft_bzero(data->bottom_line, 24);
	sq_side = data->sq_side;
	ft_memcpy(data->bottom_line, data->top_line, 24);
	n_shift(data->bottom_line, 'r', sq_side * (sq_side - 1), sq_side);
}
