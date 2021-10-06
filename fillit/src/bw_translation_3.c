/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bw_translation_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakorchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 23:02:45 by nakorchi          #+#    #+#             */
/*   Updated: 2019/12/13 21:25:53 by nakorchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		trim_col(char *buff)
{
	int		i;
	int		j;
	int		col;
	char	buff_tmp[15];

	i = 0;
	col = 3;
	j = 0;
	ft_strcpy(buff_tmp, buff);
	ft_bzero(buff, 15);
	if (buff_tmp[0] == '.' && buff_tmp[5] == '.' && buff_tmp[10] == '.')
		col = 0;
	while (i < 14)
	{
		if (!(i % 5) && col == 0)
			i++;
		if ((i == 3 || i == 8 || i == 13) && col == 3)
			i++;
		if (buff_tmp[i] != '\n')
		{
			buff[j] = buff_tmp[i];
			j++;
		}
		i++;
	}
}

static void		trim_piece(char *buff, char *t)
{
	int		i;

	i = 0;
	if (t[0] == '.' && t[1] == '.' && t[2] == '.' && t[3] == '.')
		ft_strncpy(buff, &t[5], 14);
	else
		ft_strncpy(buff, t, 14);
	trim_col(buff);
}

static void		get_bw_val_3(unsigned int *bf, char *buff)
{
	int		i;

	i = 0;
	while (i < 9)
	{
		if (buff[i] == '#')
		{
			bf[0] <<= 1;
			bf[0] |= 1 << (31 - 8);
		}
		else
			bf[0] <<= 1;
		i++;
	}
	ft_bzero(buff, 15);
}

void			init_bw_array_3(t_data *data)
{
	int		nt;
	char	buff[15];

	nt = 0;
	ft_bzero(buff, 15);
	right_col_mask(data);
	left_col_mask(data);
	top_line_mask(data);
	bottom_line_mask(data);
	while (nt < data->tmax)
	{
		data->pt = data->ipt + nt * 21;
		trim_piece(buff, (char *)data->pt);
		get_bw_val_3(data->t_ar[nt], buff);
		alignement(data, nt);
		nt++;
	}
}
