/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:49:00 by amerrouc          #+#    #+#             */
/*   Updated: 2019/02/07 15:06:05 by amerrouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		dist_sq(int x1, int y1, int x2, int y2)
{
	int	dist;

	dist = (x1 - x2) * (x1 - x2);
	dist += (y1 - y2) * (y1 - y2);
	return (dist);
}

int		det_score(t_all *all, int i, int j)
{
	int		x;
	int		y;
	int		nb;
	int		dist;

	nb = -1;
	y = 0;
	while (y < all->size_map[1])
	{
		x = 0;
		while (x < all->size_map[0])
		{
			if (all->map[y][x] != '.' && all->map[y][x] != all->letter)
			{
				dist = dist_sq(x, y, i, j);
				if (nb == -1 || dist < nb)
					nb = dist;
			}
			x++;
		}
		y++;
	}
	return (nb);
}

void	end_map(t_all *all)
{
	int	i;
	int	j;

	j = all->extr_y[0];
	while (j < all->extr_y[1])
	{
		i = all->extr_x[0];
		while (i < all->extr_x[1])
		{
			if (is_poss(all, i, j))
				all->score[j][i] = det_score(all, i, j);
			i++;
		}
		j++;
	}
}

int		score_map(t_all *all)
{
	int	i;
	int	j;

	j = 0;
	if (all->score == NULL)
	{
		if (!(all->score = (int **)malloc(sizeof(int *) * (all->size_map[1]))))
			return (-1);
		while (j < all->size_map[1])
			if (!(all->score[j++] =
						(int *)malloc(sizeof(int) * (all->size_map[0]))))
				return (-1);
	}
	j = 0;
	while (j < all->size_map[1])
	{
		i = 0;
		while (i < all->size_map[0])
			all->score[j][i++] = 0;
		j++;
	}
	set_extr(all);
	end_map(all);
	return (1);
}

void	pick_position(t_all *all)
{
	int	i;
	int	j;
	int	min;

	j = 0;
	min = -1;
	while (j < all->size_map[1])
	{
		i = 0;
		while (i < all->size_map[0])
		{
			if (all->score[j][i] && (min == -1 || all->score[j][i] < min))
			{
				min = all->score[j][i];
				all->pos[0] = i;
				all->pos[1] = j;
			}
			i++;
		}
		j++;
	}
}
