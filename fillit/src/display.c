/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakorchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 00:51:28 by nakorchi          #+#    #+#             */
/*   Updated: 2019/12/13 22:43:17 by nakorchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		write_tet(int sq_side, unsigned int *tet, int nt, char *solved)
{
	int		i;
	int		tiles;

	i = 0;
	tiles = 4;
	while (i < sq_side * sq_side)
	{
		if (tet[0] & 1 << 31)
		{
			solved[i] = 'A' + nt;
			tiles--;
		}
		bm_left_shift(tet);
		i++;
	}
}

void			display_2(char *solved, int nt, int sq_side)
{
	while (solved[nt] != '\0')
	{
		if (nt % sq_side == 0 && nt != 0)
			ft_putchar('\n');
		ft_putchar(solved[nt]);
		nt++;
	}
	ft_putchar('\n');
}

void			display(t_data *data)
{
	char	solved[646];
	int		nt;
	int		sq_side;

	sq_side = data->sq_side;
	nt = 0;
	ft_bzero(solved, 646);
	while (nt <= 168)
	{
		solved[nt] = '.';
		nt++;
	}
	nt = 0;
	while (nt < data->tmax)
	{
		write_tet(sq_side, data->t_ar[nt], nt, solved);
		nt++;
	}
	solved[sq_side * sq_side] = '\0';
	nt = 0;
	display_2(solved, nt, sq_side);
	free(data);
}

void			display_square(void)
{
	write(1, "AA\nAA\n", 6);
}
