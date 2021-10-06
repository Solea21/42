/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechapus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:04:45 by lechapus          #+#    #+#             */
/*   Updated: 2019/09/17 18:04:57 by lechapus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *begin;
	t_list *new;
	t_list *before;

	begin = NULL;
	if (lst && (*f))
	{
		begin = (*f)(lst);
		before = begin;
		lst = lst->next;
		while (lst)
		{
			new = (*f)(lst);
			before->next = new;
			before = new;
			lst = lst->next;
		}
		before->next = NULL;
	}
	return (begin);
}
