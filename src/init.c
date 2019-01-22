/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:36:28 by amerrouc          #+#    #+#             */
/*   Updated: 2019/01/22 12:15:09 by amerrouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_all	*init_all(t_all **all)
{
	if (!(*all = (t_all *)malloc(sizeof(t_all))))
		return (NULL);
	(*all)->map = NULL;
	(*all)->piece = NULL;
	(*all)->size_map[0] = 0;
	(*all)->size_map[1] = 0;
	(*all)->size_piece[0] = 0;
	(*all)->size_piece[1] = 0;
	(*all)->size_chd = 0;
	(*all)->c = '\0';
	(*all)->nb = 0;
	(*all)->cm_self[0] = 0;
	(*all)->cm_self[1] = 0;
	(*all)->cm_ene[0] = 0;
	(*all)->cm_ene[1] = 0;
	return (*all);
}

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



int		first_line(t_all *inp, int fd, int turn)
{
	char	*line;
	char	**words;

	if (turn)
		return (1);
	get_next_line(fd, &line);
	words = ft_strsplit(line, ' ');
	if (!ft_strcmp(words[2], "p1"))
		inp->c = 'O';
	else if (!ft_strcmp(words[2], "p2"))
		inp->c = 'X';
	return (1);
}

int		get_size(int *size, int fd, int *size_chd)
{
	char	*line;
	char	**words;
	int		i;
	int		old;
	int	fd2;

	get_next_line(fd, &line);
	fd2 = open("./gs.txt", O_WRONLY | O_APPEND);
	ft_putendl_fd(line, fd2);
	close(fd2);
	words = ft_strsplit(line, ' ');
	old = size[1];
	i = 0;
	while (words[i])
		i++;
	if (i != 3)
		return (0);
	size[1] = ft_atoi(words[1]);
	size[0] = ft_atoi(words[2]);
	if (size[1] != old)
		*size_chd = 1;
	else
		*size_chd = 0;
	return (1);
}

int		init_2d(char ***obj, int const *size, int size_chd)
{
	int	i;

	if (*obj != NULL && !size_chd)
		return (1);
	else if (*obj != NULL && size_chd)
		free_2d(obj);
	*obj = (char **)malloc(sizeof(char *) * (size[1] + 1));
	*(*obj + size[1]) = 0;
	i = 0;
	while (i < size[1])
		(*obj)[i++] = ft_strnew(size[0]);
	return (1);
}
