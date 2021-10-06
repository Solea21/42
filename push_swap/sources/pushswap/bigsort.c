/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechapus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 22:34:32 by lechapus          #+#    #+#             */
/*   Updated: 2021/10/03 22:34:45 by lechapus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	execute_instruction(int number, t_stack *stacks)
{
	if (number == 0)
	{
		pb(stacks);
		ft_putstr_fd("pb\n", 1);
	}
	else if (number == 2)
	{
		ra(stacks);
		ft_putstr_fd("ra\n", 1);
	}
	else if (number == 4)
	{
		pa(stacks);
		ft_putstr_fd("pa\n", 1);
	}
}

void	bigsort(t_stack *stacks)
{
	int	stack_size;
	int	num;
	int	i;
	int	j;

	stack_size = stacklen(stacks->a);
	i = 0;
	while (!is_sorted(stacks->a))
	{
		j = 0;
		while (j < stack_size)
		{
			num = stacks->a->value;
			if ((num >> i) & 1)
				execute_instruction(2, stacks);
			else
				execute_instruction(0, stacks);
			j++;
		}
		while (stacks->b)
			execute_instruction(4, stacks);
		i++;
	}
}
