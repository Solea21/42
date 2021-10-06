/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechapus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 22:31:21 by lechapus          #+#    #+#             */
/*   Updated: 2021/10/03 22:31:29 by lechapus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	pa(t_stack *stack)
{
	t_integer	*temp;

	if (!stack->b)
		return ;
	temp = stack->b->next;
	stack->b->next = stack->a;
	stack->a = stack->b;
	stack->b = temp;
}

void	pb(t_stack *stack)
{
	t_integer	*temp;

	if (!stack->a)
		return ;
	temp = stack->a->next;
	stack->a->next = stack->b;
	stack->b = stack->a;
	stack->a = temp;
}
