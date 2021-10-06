/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechapus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 00:03:50 by nakorchi          #+#    #+#             */
/*   Updated: 2019/12/14 23:13:12 by lechapus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				error(void)
{
	ft_putstr("error\n");
	return (-1);
}

t_data			*init_struct(void)
{
	t_data		*data;

	if (!(data = (t_data*)ft_memalloc(sizeof(t_data))))
		return (NULL);
	data->pt = NULL;
	return (data);
}

static t_bool	solve(t_data *data)
{
	int		nt;

	nt = 0;
	if (!init_values(data))
		return (FAILURE);
	if (data->sq_side == 2)
	{
		return (SUCCESS);
	}
	if (data->sq_side == 3)
		init_bw_array_3(data);
	else
		init_bw_array(data);
	while (data->sq_side <= 13)
	{
		if (!backtrack(data, nt))
		{
			data->sq_side++;
			if ((init_bw_array(data)) == FAILURE)
				return (FAILURE);
		}
		else
			return (SUCCESS);
	}
	return (FAILURE);
}

t_bool			master_0(t_data *data)
{
	if (validate_input(data) == FAILURE)
		return (FAILURE);
	if (solve(data))
	{
		if (data->sq_side == 2)
			display_square();
		else
			display(data);
		return (SUCCESS);
	}
	return (FAILURE);
}

int				main(int ac, char **av)
{
	int			fd;
	int			ret;
	t_data		*data;

	if (2 == ac && av[1])
	{
		if ((data = init_struct()) == NULL)
			return (error());
		fd = open(av[1], O_RDONLY);
		ret = read(fd, data->ipt, 600);
		if (ret < 0 || 546 < ret || (ret + 1) % 21 != 0)
			return (error());
		close(fd);
		data->tmax = (ret + 1) / 21;
		if (master_0(data) == SUCCESS)
			return (0);
	}
	return (error());
}
