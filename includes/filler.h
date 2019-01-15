/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 10:15:39 by amerrouc          #+#    #+#             */
/*   Updated: 2019/01/15 12:52:55 by amerrouc         ###   ########.fr       */
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
	char		c;
	int			nb;
}				t_all;

t_all			*init_all(void);
t_list			*pc_start(t_all *all);
int				first_line(t_all *inp, int fd);
int				get_size(int *size, int fd);
int				init_2d(char ***obj, int const *size);
void			count_blocks(t_all *inp);
int				is_poss(t_all *all, t_list *info);
int				check_line(t_all *all, char *str, int dtp);
int				free_2d(char ***str);
int				put_piece(t_all *all,t_list *pos);
int				det_score(t_all *all, int *position);
char			**score_map(void);
void			end_map(char **score_map, t_all *all, t_list *position);
void			pick_position(char **score, t_list *pos);

#endif
