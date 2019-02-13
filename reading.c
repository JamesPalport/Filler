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

int		get_size_map(t_all *all, int fd)
{
	char	*tmp;
	char	c;
	int		num;

	if (ft_read(fd, &tmp, 8) <= 0)
		return (0);
	if (ft_strncmp("Plateau", tmp, 7))
		return (0);
	free(tmp);
	num = 0;
	while (read(fd, &c, 1) > 0 && ft_isdigit(c))
		num = num * 10 + c - '0';
	if (all->size_map[1] && all->size_map[1] != num)
		return (0);
	all->size_map[1] = num;
	num = 0;
	while (read(fd, &c, 1) > 0 && ft_isdigit(c))
		num = num * 10 + c - '0';
	if (all->size_map[0] && all->size_map[0] != num)
		return (0);
	all->size_map[0] = num;
	skip_lines(1, fd);
	return (1);
}

int		get_size_piece(t_all *all, int fd)
{
	char	*tmp;
	char	c;
	int		num;

	if (ft_read(fd, &tmp, 6) <= 0)
		return (0);
	if (ft_strncmp("Piece", tmp, 5))
		return (0);
	free(tmp);
	num = 0;
	while (read(fd, &c, 1) > 0 && ft_isdigit(c))
		num = num * 10 + c - '0';
	all->size_piece[1] = num;
	num = 0;
	while (read(fd, &c, 1) > 0 && ft_isdigit(c))
		num = num * 10 + c - '0';
	all->size_piece[0] = num;
	skip_lines(1, fd);
	return (1);
}

int		get_map(t_all *all, int fd)
{
	int		i;
	char	*line;
	char	c;

	i = 0;
	line = NULL;
	while (i < all->size_map[1])
	{
		c = 0;
		while (c != ' ')
			if (read(fd, &c, 1) < 0)
				return (-1);
		if (ft_read(fd, &line, all->size_map[0]) < 0)
			return (0);
		if (!check_line(all, line, 0))
		{
			free(line);
			return (0);
		}
		ft_strncpy(all->map[i], line, all->size_map[0]);
		free(line);
		i++;
		skip_lines(1, fd);
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
	if (ft_read(fd, &line, all->size_piece[0]) < 0)
			return (0);
		if (!check_line(all, line, 1))
		{
			free(line);
			return (0);
		}
		ft_strncpy(all->piece[i], line, all->size_piece[0]);
		free(line);
		i++;
		skip_lines(1, fd);
	}
	return (1);
}

int		reader(t_all *all, int fd)
{
	if (!get_size_map(all, fd))
		return (freeall(all));
	if (!all->map)
		init_map(all);
	if (!all->map)
		return (freeall(all));
	skip_lines(1, fd);
	if (!get_map(all, fd))
		return (freeall(all));
	if (!get_size_piece(all, fd))
		return (freeall(all));
	if (!get_piece(all, fd))
		return (freeall(all));
	return (1);
}
