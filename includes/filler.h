/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 10:15:39 by amerrouc          #+#    #+#             */
/*   Updated: 2019/01/22 12:16:21 by amerrouc         ###   ########.fr       */
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
	int			size_map[2];
	int			size_piece[2];
	int			size_chd;
	char		c;
	int			nb;
	int			cm_self[2];
	int			cm_ene[2];
}				t_all;

t_all			*init_all(t_all **all);
int				*pc_start(t_all *all);
int				first_line(t_all *inp, int fd, int turn);
int				get_size(int *size, int fd, int *size_chd);
int				init_2d(char ***obj, int const *size, int size_chd);
void			count_blocks(t_all *inp);
int				is_poss(t_all *all, int *info);
int				check_line(t_all *all, char *str, int dtp);
int				free_2d(char ***str);
int				put_piece(t_all *all,int *pos);
int				det_score(t_all *all, int *position);
char			**score_map(t_all *all);
void			end_map(char **score_map, t_all *all, int *position);
void			pick_position(char **score, int *pos);
int				reading(t_all *inp, int fd);
void			center_mass(t_all *all);

#endif
