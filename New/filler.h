/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 10:15:39 by amerrouc          #+#    #+#             */
/*   Updated: 2019/01/31 13:12:07 by amerrouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H

# define FILLER_H

# include <stdio.h>
# include <string.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct	s_all
{
	char		**map;
	char		**piece;
	int			**score;
	int			size_map[2];
	int			size_piece[2];
	char		letter;
	int			nb_sqr;
	int			extr_x[2];
	int			extr_y[2];
	int			cm_ene[3];
	int			pos[2];
	int			end;
}				t_all;

int				skip_lines(int n, int fd);
void			reset_dbchar(char ***map, int size);

void			init_all(t_all *all);
void			begin_prog(t_all *all, int fd);
void			init_map(t_all *all);
void			init_piece(t_all *all);
void			get_size(t_all *all, int fd);
void			get_map(t_all *all, int fd);
void			get_piece(t_all *all, int fd);
void			reader(t_all *all);
void			count_blocs(t_all *all);
//void			center_mass(t_all *all);
//void			pc_start(t_all *all);
int				score_map(t_all *all);
void			set_extr(t_all *all);
int				is_poss(t_all *all, int x, int y);
int				det_score(t_all *all, int i, int j);
void			end_map(t_all *all);
void			pick_position(t_all *all);

#endif
