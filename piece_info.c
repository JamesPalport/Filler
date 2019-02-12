/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 10:44:27 by amerrouc          #+#    #+#             */
/*   Updated: 2019/02/07 14:49:39 by amerrouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	adj_extr(t_all *all)
{
	all->extr_x[0] -= all->size_piece[0];
	all->extr_x[1] += all->size_piece[0];
	all->extr_y[0] -= all->size_piece[1];
	all->extr_y[1] += all->size_piece[1];
	all->extr_x[0] = all->extr_x[0] < 0 ? 0 : all->extr_x[0];
	all->extr_x[1] = all->extr_x[1] > all->size_map[0] ?
		all->size_map[0] : all->extr_x[1];
	all->extr_y[0] = all->extr_y[0] < 0 ? 0 : all->extr_y[0];
	all->extr_y[1] = all->extr_y[1] > all->size_map[1] ?
		all->size_map[0] : all->extr_y[1];
}

void	set_extr(t_all *all)
{
	int	i;
	int	j;

	j = 0;
	while (j < all->size_map[1])
	{
		i = 0;
		while (i < all->size_map[0])
		{
			if (all->map[j][i] == all->letter)
			{
				if (j > all->extr_y[1])
					all->extr_y[1] = j;
				if (all->extr_y[0] == -1 || j < all->extr_y[0])
					all->extr_y[0] = j;
				if (i > all->extr_x[1])
					all->extr_x[1] = i;
				if (all->extr_x[0] == -1 || i < all->extr_x[0])
					all->extr_x[0] = i;
			}
			i++;
		}
		j++;
	}
	adj_extr(all);
}
