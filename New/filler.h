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
	int			**score;
	int			size_map[2];
	int			size_piece[2];
	int			size_chd;
	char		letter[3];
	int			nb_sqr;
	int			cm_self[2];
	int			cm_ene[2];
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
void			pc_start(t_all *all);
void			score_map(t_all *all);

#endif
