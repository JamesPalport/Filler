/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 10:44:27 by amerrouc          #+#    #+#             */
/*   Updated: 2019/01/11 13:08:53 by amerrouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_list	*pc_start(t_all *all)
{
	t_list	*pos;
	int		position[2];
	int		i;
	int		j;

	position[0] = -1;
	j = 0;
	while (j < all->size_map[1] && position[0] == -1)
	{
		i = 0;
		while (i < all->size_map[0] && position[0] == -1)
		{
			if (all->map[j][i] == all->c)
			{
				position[0] = i;
				position[1] = j;
			}
			i++;
		}
		j++;
	}
	pos = ft_lstnew(position, sizeof(int) * 2);
	return (pos);
}
