/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 10:44:27 by amerrouc          #+#    #+#             */
/*   Updated: 2019/01/30 16:07:30 by amerrouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	pc_start(t_all *all)
{
	int		i;
	int		j;

	j = 0;
	if (all->retry[0])
	while (j < all->size_map[1])
	{
		i = 0;
		while (i < all->size_map[0])
		{
			if (all->map[j][i] == all->letter[0]
					&& (all->pos[0] == -10 || (all->vect[1] * j > all->pos[1]
					|| all->vect[0] * i > all->pos[0])))
			{
				all->pos[0] = i;
				all->pos[1] = j;
			}
			i++;
		}
		j++;
	}
}
