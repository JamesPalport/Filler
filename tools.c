/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:51:21 by amerrouc          #+#    #+#             */
/*   Updated: 2019/02/08 14:29:26 by amerrouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		skip_lines(int n, int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	while (i < n && get_next_line(fd, &line))
	{
		i++;
		free(line);
	}
	if (i != n)
		return (0);
	return (1);
}

void	freedbchar(char ***src)
{
	int	i;

	i = 0;
	while ((*src)[i])
	{
		free((*src)[i]);
		i++;
	}
	free(*src);
	*src = NULL;
}

void	freescore(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->size_map[1])
		free(all->score[i++]);
	free(all->score);
}

int		freeall(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->size_map[1])
	{
		if (all->map && all->map[i])
			free(all->map[i]);
		if (all->score && all->score[i])
			free(all->score[i]);
		i++;
	}
	free(all->map);
	free(all->score);
	all->map = NULL;
	all->score = NULL;
	i = -1;
	while (++i < all->size_piece[1])
		if (all->piece && all->piece[i])
			free(all->piece[i]);
	free(all->piece);
	all->piece = NULL;
	all->end = 1;
	return (0);
}
