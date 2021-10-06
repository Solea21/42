/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechapus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 22:36:11 by lechapus          #+#    #+#             */
/*   Updated: 2021/10/03 22:36:28 by lechapus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../../libraries/libft.h"
# include "../list/list.h"
# include "../parser/parser.h"

void	ft_heapsort(int *arr, int n);
void	very_smallsort(t_stack *stacks);
void	smallsort(t_stack *stacks);
void	bigsort(t_stack *stack);

#endif
