/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 12:27:37 by amerrouc          #+#    #+#             */
/*   Updated: 2019/02/07 14:50:07 by amerrouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	in_lines(t_all *all, int *pos, int *put, int j)
{
	int	pos_x;
	int	pos_y;
	int	i;

	i = 0;
	pos_x = pos[0];
	pos_y = pos[1] + j;
	if (pos_y < 0)
		return ;
	while (i < all->size_piece[0] && pos_x < all->size_map[0])
	{
		if (pos_x < 0)
			pos_x = 0;
		if (all->piece[j][i] == '*')
		{
			put[1]++;
			if (all->map[pos_y][pos_x] == all->letter)
				put[0]++;
			else if (all->map[pos_y][pos_x] != '.')
				put[0] += 10;
		}
		i++;
		pos_x = i + pos[0];
	}
}

int		is_poss(t_all *all, int x, int y)
{
	int	j;
	int	put[2];
	int	pos_y;
	int	info[2];

	info[0] = x;
	info[1] = y;
	j = 0;
	put[0] = 0;
	put[1] = 0;
	pos_y = info[1];
	while (j < all->size_piece[1] && pos_y < all->size_map[1])
	{
		in_lines(all, info, put, j);
		j++;
		pos_y = j + info[1];
	}
	if (put[0] == 1 && put[1] == all->nb_sqr)
		return (1);
	return (0);
}
