/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechapus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 22:30:45 by lechapus          #+#    #+#             */
/*   Updated: 2021/10/03 22:30:54 by lechapus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_integer	*add_int_value(t_integer *stack, int value)
{
	t_integer	*tmp;

	tmp = malloc(sizeof(t_integer));
	if (tmp)
	{
		tmp->value = value;
		tmp->next = stack;
	}
	return (tmp);
}

int	is_sorted(t_integer *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	stacklen(t_integer *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

void	free_stack(t_stack *stacks)
{
	t_integer	*tmp;

	tmp = NULL;
	while (stacks->a)
	{
		tmp = stacks->a->next;
		free(stacks->a);
		stacks->a = tmp;
	}
	while (stacks->b)
	{
		tmp = stacks->b->next;
		free(stacks->b);
		stacks->b = tmp;
	}
}
