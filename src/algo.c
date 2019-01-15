/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:49:00 by amerrouc          #+#    #+#             */
/*   Updated: 2019/01/15 12:55:17 by amerrouc         ###   ########.fr       */
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

char	**score_map(void)
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
	score[j] = NULL;
	return (score);
}

void	pick_position(char **score, t_list *pos)
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
				position[0] = i + ((int *)pos->content)[0] - 2;
				position[1] = j + ((int *)pos->content)[1] - 2;
			}
			i++;
		}
		j++;
	}
	((int *)pos->content)[0] = position[0];
	((int *)pos->content)[1] = position[1];
}

void	end_map(char **score, t_all *all, t_list *position)
{
	t_list	pos;
	int	p[2];
	int	i;
	int	j;

	pos.content = p;
	j = 0;
	while (j < 5)
	{
		i = 0;
		while (i < 5)
		{
			p[0] = i + ((int *)position->content)[0] - 2;
			p[1] = j + ((int *)position->content)[1] - 2;
			score[j][i] *= is_poss(all, &pos);
			if (!score[j][i])
				score[j][i] = '0';
			i++;
		}
		j++;
	}
}
