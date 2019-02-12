/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:04:30 by amerrouc          #+#    #+#             */
/*   Updated: 2018/11/13 16:03:11 by amerrouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= (int)'a') && (c <= (int)'z'))
		return (1);
	if ((c >= (int)'A') && (c <= (int)'Z'))
		return (1);
	return (0);
}
