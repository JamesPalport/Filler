/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 10:44:27 by amerrouc          #+#    #+#             */
/*   Updated: 2019/01/22 12:36:57 by amerrouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		*pc_start(t_all *all)
{
	int		*position;
	int		i;
	int		j;

	if (!(position = (int *)malloc(sizeof(int) * 2)))
		return (NULL);
	position[0] = all->size_map[0];
	j = 0;
	while (j < all->size_map[1])
	{
		i = 0;
		while (i < all->size_map[0])
		{
			if (all->map[j][i] == all->c )
			{
				position[0] = i;
				position[1] = j;
			}
			i++;
		}
		j++;
	}
	return (position);
}
