/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechapus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 22:33:43 by lechapus          #+#    #+#             */
/*   Updated: 2021/10/03 22:33:52 by lechapus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../../libraries/libft.h"
# include "../list/list.h"
# include <limits.h>

char	**init_variables(int argc, char **argv, t_stack *stacks, int *i);
void	parse(char **argv, int nb_value);
void	exit_program(char *message);

#endif
