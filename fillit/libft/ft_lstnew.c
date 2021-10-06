/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakorchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 03:28:41 by nakorchi          #+#    #+#             */
/*   Updated: 2019/12/13 22:30:18 by nakorchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*freshl;

	(void)content_size;
	if (!(freshl = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
		freshl->content = NULL;
	ft_memcpy(freshl, content, content_size);
	return (freshl);
}
