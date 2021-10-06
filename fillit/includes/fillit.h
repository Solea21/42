/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakorchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 22:24:37 by nakorchi          #+#    #+#             */
/*   Updated: 2019/12/13 22:39:21 by nakorchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdint.h>

typedef enum		e_bool
{
	FAILURE,
	SUCCESS
}					t_bool;

typedef struct		s_sos
{
	int		i_s;
	int		i_bf;
	int		tiles;
}					t_sos;

typedef struct		s_data
{
	char			ipt[600];
	unsigned int	t_ar[26][6];
	int				tmax;
	void			*pt;
	void			*ipt_0;
	int				sq_side;
	int				area;
	unsigned int	solve_map[6];
	unsigned int	right_col[6];
	unsigned int	left_col[6];
	unsigned int	top_line[6];
	unsigned int	bottom_line[6];
}					t_data;

void				right_col_mask(t_data *data);
void				left_col_mask(t_data *data);
void				top_line_mask(t_data *data);
void				bottom_line_mask(t_data *data);
int					main(int ac, char **av);
int					error();
t_bool				tet_right_shift(t_data *data, int nt);
void				alignement(t_data *data, int nt);
void				display(t_data *data);
t_bool				validate_input(t_data *tet_id);
void				display_square();
void				get_bw_val(t_data *data, char *n_tet, int sq_side, int nt);
t_bool				init_bw_array(t_data *data);
void				n_shift(unsigned int *bf, char c, int rounds, int sq_side);
void				xor_bf(unsigned int *solve_map, unsigned int *mask);
t_bool				and_bf(unsigned int *bf1, unsigned int *bf2);
t_bool				init_bw_val(t_data *data);
void				write_bf(unsigned int *dst, unsigned int *src);
void				init_bw_array_3(t_data *data);
t_bool				init_masta_bf(t_data *data);
void				bm_right_shift(unsigned int *bf);
void				bm_left_shift(unsigned int *bf);
void				bm_bottom_shift(unsigned int *bf, int sq_side);
void				bm_top_shift(unsigned int *bf, int sq_side);
t_bool				backtrack(t_data *data, int nt);
int					tet_width(unsigned int *bf, int sq_sidei, t_data *data);
t_bool				init_values(t_data *data);

#endif
