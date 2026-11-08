/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalero <svalero@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 19:06:43 by svalero           #+#    #+#             */
/*   Updated: 2026/11/08 19:06:56 by svalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunks.h"

/* Converts a negative rotation position into an array index. */
int	sim_positive_pos(int pos, int size)
{
	if (size < 2)
		return (0);
	if (pos < 0)
		return (pos + size);
	return (pos);
}

/* Rotates an array to the left by the requested number of positions. */
void	sim_rotate_left(int *array, int size, int pos)
{
	int	i;
	int	first;

	if (size < 2)
		return ;
	while (pos-- > 0)
	{
		first = array[0];
		i = 0;
		while (i < size - 1)
		{
			array[i] = array[i + 1];
			i++;
		}
		array[size - 1] = first;
	}
}

/* Removes the first element of an array. */
void	sim_remove_top(int *array, int size)
{
	if (size < 2)
		return ;
	ft_memmove(array, array + 1, sizeof(int) * (size - 1));
}

/* Inserts a new element at the beginning of an array. */
void	sim_push_top(int *array, int *size, int target)
{
	ft_memmove(array + 1, array, sizeof(int) * (*size));
	array[0] = target;
	(*size)++;
}
