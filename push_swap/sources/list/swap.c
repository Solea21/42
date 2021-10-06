/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechapus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 22:32:36 by lechapus          #+#    #+#             */
/*   Updated: 2021/10/03 22:32:45 by lechapus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	sa(t_stack *number)
{
	t_integer	*temp;

	if (!number->a || !number->a->next)
		return ;
	temp = number->a->next;
	number->a->next = number->a->next->next;
	temp->next = number->a;
	number->a = temp;
}

void	sb(t_stack *number)
{
	t_integer	*temp;

	if (!number->b || !number->b->next)
		return ;
	temp = number->b->next;
	number->b->next = number->b->next->next;
	temp->next = number->b;
	number->b = temp;
}

void	ss(t_stack *number)
{
	sa(number);
	sb(number);
}
