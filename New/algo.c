/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:49:00 by amerrouc          #+#    #+#             */
/*   Updated: 2019/01/22 12:16:13 by amerrouc         ###   ########.fr       */
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

int	det_score(t_all *all, int *position)
{
	int	xm;
	int	i;
	int	j;
	int	min[2];

	j = -3;
	xm = -3;
	min[0] = 10;
	min[1] = 10;
	while (position[1] + j < 0)
		j++;
	while (position[0] + xm < 0)
		xm++;
	while (j < 3)
	{
		i = xm;
		while (i < 3)
		{
			if (all->map[position[1] + j][position[0] + i] != '.')
			{
				min[0] = ft_min(min[0], i);
				min[1] = ft_min(min[1], j);
			}
			i++;
		}
	}
	return (ft_max(min[0], min[1]));
}

void	aggro(char **score, t_all *all)
{
	int i;
	int	j;
	int	aim[2];

	aim[0] = all->cm_ene[0] - all->cm_self[0];
	aim[1] = all->cm_ene[1] - all->cm_self[1];
	if (aim[0] > 0)
		aim[0] = 1;
	else if (aim[0] < 0)
		aim[0] = -1;
	if (aim[1] > 0)
		aim[1] = 1;
	else if (aim[1] < 0)
		aim[1] = -1;
	j = 2 + aim[1] - 1;
	while (j < 5 && j < 3 + aim[1])
	{
		i = 2 + aim[0] - 1;
		while (i < 5 && i < 3 + aim[0])
		{
			if (i >= 0 && j >= 0)
				score[j][i]++;
			i++;
		}
		j++;
	}
}

char	**score_map(t_all *all)
{
	char	**score;
	int	i;
	int	j;

	j = 0;
	if (!(score = (char **)malloc(sizeof(char *) * 5)))
		return (NULL);
	while (j < 7)
		if (!(score[j++] = (char *)malloc(sizeof(char) * 5)))
			return (NULL);
	j = 0;
	while (j < 5)
	{
		i = 0;
		while (i < 5)
		{
			score[j][i] = '3' - ft_max(abs(i - 2), abs(j - 2));
			i++;
		}
		score[j][i] = '\0';
		j++;
	}
	aggro(score, all);
	score[j] = NULL;
	return (score);
}

void	pick_position(char **score, int *pos)
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
			if (score[j][i] && score[j][i] > max)
			{
				max = score[j][i];
				position[0] = i + pos[0] - 2;
				position[1] = j + pos[1] - 2;
			}
			i++;
		}
		j++;
	}
	pos[0] = position[0];
	pos[1] = position[1];
}

void	end_map(char **score, t_all *all, int *position)
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
			p[0] = i + position[0] - 2;
			p[1] = j + position[1] - 2;
			score[j][i] *= is_poss(all, p);
			if (!score[j][i])
				score[j][i] = '0';
			i++;
		}
		j++;
	}
}
