/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:36:28 by amerrouc          #+#    #+#             */
/*   Updated: 2019/01/11 13:08:12 by amerrouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_all	*init_all(void)
{
	t_all	*all;

	if (!(all = (t_all *)malloc(sizeof(t_all))))
		return (NULL);
	all->map = NULL;
	all->piece = NULL;
	all->size_map[0] = 0;
	all->size_map[1] = 0;
	all->size_piece[0] = 0;
	all->size_piece[1] = 0;
	all->c = 0;
	all->nb = 0;
	return (all);
}

int		first_line(t_all *inp, int fd)
{
	char	*line;
	char	**words;
	int		i;

	get_next_line(fd, &line);
	words = ft_strsplit(line, ' ');
	i = 0;
	if (!ft_strcmp(words[2], "p1"))
		inp->c = 'X';
	else if (!ft_strcmp(words[2], "p2"))
		inp->c = 'O';
	return (1);
}

int		get_size(int *size, int fd)
{
	char	*line;
	char	**words;

	get_next_line(fd, &line);
	words = ft_strsplit(line, ' ');
	size[1] = ft_atoi(words[1]);
	size[0] = ft_atoi(words[2]);
	return (1);
}

int		init_2d(char ***obj, int const *size)
{
	int	i;

	*obj = (char **)malloc(sizeof(char *) * (size[1] + 1));
	*(*obj + size[1]) = 0;
	i = 0;
	while (i < size[1])
		(*obj)[i++] = ft_strnew(size[0]);
	return (1);
}
