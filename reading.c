/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:36:10 by amerrouc          #+#    #+#             */
/*   Updated: 2019/02/08 15:28:01 by amerrouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	extr_size(t_all *all, char *line, int dst)
{
	int	i;
	int	prev[2];

	i = 0;
	if (dst == 0)
	{
		prev[0] = all->size_map[0];
		prev[1] = all->size_map[1];
		all->size_map[1] = ft_atoi(line);
		while (ft_isdigit(line[i]))
			i++;
		all->size_map[0] = ft_atoi(line + i);
		if (prev[0] && prev[1])
			if (prev[0] != all->size_map[0] || (prev[1] != all->size_map[1]))
				return ;
	}
	if (dst == 1)
	{
		all->size_piece[1] = ft_atoi(line);
		while (ft_isdigit(line[i]))
			i++;
		all->size_piece[0] = ft_atoi(line + i);
	}
}

int		get_size(t_all *all, int fd)
{
	char	*tmp;

	if (get_next_line(fd, &tmp) <= 0)
	{
		if (tmp)
			free(tmp);
		return (0);
	}
	if (!ft_strncmp("Plateau", tmp, 7))
		extr_size(all, tmp + 8, 0);
	else if (!ft_strncmp("Piece", tmp, 5))
		extr_size(all, tmp + 6, 1);
	free(tmp);
	return (1);
}

int		get_map(t_all *all, int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	while (i < all->size_map[1])
	{
		if (get_next_line(fd, &line) < 0)
			return (0);
		if (!check_line(all, line + 4, 0))
		{
			free(line);
			return (0);
		}
		ft_strncpy(all->map[i], line + 4, all->size_map[0]);
		free(line);
		line = NULL;
		i++;
	}
	return (1);
}

int		get_piece(t_all *all, int fd)
{
	int		i;
	char	*line;

	init_piece(all);
	i = 0;
	while (i < all->size_piece[1])
	{
		if (get_next_line(fd, &line) < 0)
			return (0);
		if (!check_line(all, line, 1))
		{
			free(line);
			return (0);
		}
		ft_strncpy(all->piece[i], line, all->size_piece[0]);
		free(line);
		line = NULL;
		i++;
	}
	return (1);
}

int		reader(t_all *all, int fd)
{
	if (!get_size(all, fd))
		return (freeall(all));
	if (!all->map)
		init_map(all);
	if (!all->map)
		return (freeall(all));
	skip_lines(1, fd);
	if (!get_map(all, fd))
		return (freeall(all));
	if (!get_size(all, fd))
		return (freeall(all));
	if (!get_piece(all, fd))
		return (freeall(all));
	return (1);
}
