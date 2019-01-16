/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:13:20 by amerrouc          #+#    #+#             */
/*   Updated: 2019/01/16 16:03:23 by amerrouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int		fd;
	t_all	all;
	t_list	*pos;
	char	**score;
	int		gu;
	int		fd2;

	if (!(init_all(&all)))
		return (0);
	fd = 0;
//	fd = open("./tt", O_RDONLY);
	gu = 1;
	fd2 = open("map.txt", O_WRONLY);
	while (gu)
	{
		if (reading(&all, fd))
		{
		pos = pc_start(&all);
		score = score_map();
		end_map(score, &all, pos);
		pick_position(score, pos);
		if (((int *)pos->content)[0] < 0)
			gu = 0;
		if (gu)
		{
			ft_printf("%d %d\n", ((int *)pos->content)[1], ((int *)pos->content)[0]);
			/*put_piece(&all, pos);*/
			/*put_2d(&all->map, 1);
			put_2d(&all->map, fd2);*/
		}
		}
		else
			gu = 0;
	}
	close(fd2);
//	close(fd);
	return 0;
}
