/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:49:00 by amerrouc          #+#    #+#             */
/*   Updated: 2019/01/31 13:49:50 by amerrouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	det_score(t_all *all, int i, int j)
{
	int	nb;
	int	dx;
	int	dy;

	dx = i - all->size_map[0] / 2;
	dy = j - all->size_map[1] / 2;
	dx = dx >= 0 ? dx : -dx;
	dy = dy >= 0 ? dy : -dy;
	nb = dx + dy + 1;
	if (all->cm_ene[2] >= 20)
	{
		dx = i - all->cm_ene[0];
		dy = j - all->cm_ene[1];
		dx = dx >= 0 ? dx : -dx;
		dy = dy >= 0 ? dy : -dy;
		nb += dx + dy;
	}
	return (nb);
}

/*void	pick_direc(t_all *all)
{
	if (all->vect[0] || all->vect[1])
		return ;
	if (abs(all->cm_self[0] - all->size_map[0] / 2)
			< abs(all->cm_ene[0] - all->size_map[0] / 2))
	{
		all->vect[0] = 0;
		all->vect[1] = 1;
	}
	else if (abs(all->cm_self[1] - all->size_map[1] / 2)
			< abs(all->cm_ene[1] - all->size_map[1] / 2))
	{
		all->vect[0] = 1;
		all->vect[1] = 0;
	}
	else
	{
		all->vect[0] = all->cm_ene[0] - all->cm_self[0];
		all->vect[1] = all->cm_ene[1] - all->cm_self[1];
	}
	if (all->vect[0] > 0)
		all->vect[0] = 1;
	else if (all->vect[0] < 0)
		all->vect[0] = -1;
	if (all->vect[1] > 0)
		all->vect[1] = 1;
	else if (all->vect[1] < 0)
		all->vect[1] = -1;
}*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/*void	aggro(t_all *all)
{
	int i;
	int	j;
	
	int	fd;
	fd = open("vect", O_WRONLY | O_APPEND);
	pick_direc(all);
	ft_dprintf(fd, "vect :%d %d\ncm_ene\t:%d %d\ncm_self\t:%d %d\n-----\n",
			all->vect[0], all->vect[1], all->cm_ene[0], all->cm_ene[1], all->cm_self[0], all->cm_self[1]);
	j = 2 + all->vect[1] - 1;
	while (j < 5 && j < 3 + all->vect[1])
	{
		i = 2 + all->vect[0] - 1;
		while (i < 5 && i < 3 + all->vect[0])
		{
			if (i >= 0 && j >= 0)
				all->score[j][i] += 2;
			i++;
		}
		j++;
	}
}*/

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
	//	aggro(all);
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
			if (all->score[j][i] && (min == -1 ||  all->score[j][i] < min))
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

