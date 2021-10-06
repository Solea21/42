/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_box_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakorchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 04:31:37 by nakorchi          #+#    #+#             */
/*   Updated: 2019/12/13 22:06:34 by nakorchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		bm_right_shift(unsigned int *bf)
{
	unsigned int	t[6];
	int				i;

	i = 5;
	ft_memcpy(t, bf, (size_t)24);
	while (i)
	{
		t[i] >>= 1;
		if (0 < i && (t[i - 1] & 1))
			t[i] |= (1 << 31);
		i--;
	}
	t[i] >>= 1;
	ft_memcpy(bf, t, (size_t)24);
}

void		bm_left_shift(unsigned int *bf)
{
	unsigned int	t[6];
	int				i;

	i = 0;
	ft_bzero(t, 24);
	ft_memcpy(t, bf, (size_t)24);
	while (i < 6)
	{
		t[i] <<= 1;
		if (i < 5 && (t[i + 1] & (1 << 31)))
			t[i] |= 1;
		i++;
	}
	ft_memcpy(bf, t, (size_t)24);
}

void		bm_bottom_shift(unsigned int *bf, int sq_side)
{
	while (sq_side)
	{
		bm_right_shift(bf);
		sq_side--;
	}
}

void		bm_top_shift(unsigned int *bf, int sq_side)
{
	while (sq_side)
	{
		bm_left_shift(bf);
		sq_side--;
	}
}

void		write_bf(unsigned int *dst, unsigned int *src)
{
	int		i;

	i = 0;
	while (i < 6)
	{
		dst[i] |= src[i];
		i++;
	}
}
