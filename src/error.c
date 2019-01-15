/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 13:52:14 by amerrouc          #+#    #+#             */
/*   Updated: 2019/01/11 13:57:02 by amerrouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	free_2d(char ***str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	while ((*str)[i])
		free((*str)[i++]);
	free(*str);
	*str = NULL;
	return (0);
}
