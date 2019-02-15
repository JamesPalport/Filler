/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:49:03 by amerrouc          #+#    #+#             */
/*   Updated: 2019/02/15 10:07:58 by amerrouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	prog(t_all *all)
{
	count_blocs(all);
	score_map(all);
	pick_position(all);
	if (is_poss(all, all->pos[0], all->pos[1]))
		ft_printf("%d %d\n", all->pos[1], all->pos[0]);
	else
	{
		ft_putstr("0 0\n");
		all->end = 1;
	}
}

int		main(void)
{
	t_all all;

	init_all(&all);
	if (!begin_prog(&all, 0))
		return (0);
	while (!all.end)
	{
		if (reader(&all, 0))
			prog(&all);
		else
			ft_putendl_fd("Error", 2);
	}
	freeall(&all);
	return (0);
}
