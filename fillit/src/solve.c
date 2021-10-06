/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakorchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 22:01:47 by nakorchi          #+#    #+#             */
/*   Updated: 2019/12/13 22:01:51 by nakorchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_bool		backtrack(t_data *data, int nt)
{
	int		first;

	first = 1;
	if (nt == data->tmax)
		return (SUCCESS);
	while (first || tet_right_shift(data, nt))
	{
		first = 0;
		if (!and_bf(data->solve_map, data->t_ar[nt]))
		{
			write_bf(data->solve_map, data->t_ar[nt]);
			if (backtrack(data, nt + 1))
				return (SUCCESS);
			xor_bf(data->solve_map, data->t_ar[nt]);
		}
	}
	alignement(data, nt);
	return (FAILURE);
}
