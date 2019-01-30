/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:49:00 by amerrouc          #+#    #+#             */
/*   Updated: 2019/01/30 15:18:18 by amerrouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	abs(int nb)
{
	return (nb >= 0 ? nb : -nb);
}

int	ft_min(int a, int b)
{
	if (a > b)
		return b;
	return (a);
}

int	ft_max(int a, int b)
{
	if (a < b)
		return b;
	return (a);
}

int	det_score(t_all *all)
{
	int	xm;
	int	i;
	int	j;
	int	min[2];

	j = -3;
	xm = -3;
	min[0] = 10;
	min[1] = 10;
	while (all->pos[1] + j < 0)
		j++;
	while (all->pos[0] + xm < 0)
		xm++;
	while (j < 3)
	{
		i = xm;
		while (i < 3)
		{
			if (all->map[all->pos[1] + j][all->pos[0] + i] != '.')
			{
				min[0] = ft_min(min[0], i);
				min[1] = ft_min(min[1], j);
			}
			i++;
		}
	}
	return (ft_max(min[0], min[1]));
}

void	pick_direc(t_all *all)
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
}

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	aggro(t_all *all)
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
}

void	score_map(t_all *all)
{
	int	i;
	int	j;

	j = 0;
	if (!(all->score = (char **)malloc(sizeof(char *) * 5)))
		return ;
	while (j < 7)
		if (!(all->score[j++] = (char *)malloc(sizeof(char) * 5)))
			return ;
	j = 0;
	while (j < 5)
	{
		i = 0;
		while (i < 5)
		{
			all->score[j][i] = '3' - ft_max(abs(i - 2), abs(j - 2));
			i++;
		}
		all->score[j][i] = '\0';
		j++;
	}
	pick_direc(all);
	//	aggro(all);
	all->score[j] = NULL;
}

void	pick_position(t_all *all)
{
	int	position[2];
	int	i;
	int	j;
	int	max;

	j = 0;
	position[0] = -1;
	position[1] = -1;
	max = -1;
	while (j < 5)
	{
		i = 0;
		while (i < 5)
		{
			if (all->score[j][i] && all->score[j][i] > max)
			{
				max = all->score[j][i];
				position[0] = i + all->pos[0] - 2;
				position[1] = j + all->pos[1] - 2;
			}
			i++;
		}
		j++;
	}
	all->pos[0] = position[0];
	all->pos[1] = position[1];
}

void	end_map(t_all *all)
{
	int	p[2];
	int	i;
	int	j;

	j = 0;
	while (j < 5)
	{
		i = 0;
		while (i < 5)
		{
			p[0] = i + all->pos[0] - 2;
			p[1] = j + all->pos[1] - 2;
			all->score[j][i] *= is_poss(all, p);
			if (!all->score[j][i])
				all->score[j][i] = '0';
			i++;
		}
		j++;
	}
}
