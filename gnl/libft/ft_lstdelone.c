/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechapus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:03:22 by lechapus          #+#    #+#             */
/*   Updated: 2019/09/17 18:03:29 by lechapus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	if (*alst && alst)
	{
		if ((*alst)->content)
		{
			if (del)
				del((*alst)->content, (*alst)->content_size);
		}
		free(*alst);
		*alst = NULL;
	}
}
