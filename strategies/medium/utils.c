/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalero <svalero@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 14:04:17 by svalero           #+#    #+#             */
/*   Updated: 2026/11/08 18:33:35 by svalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunks.h"

/* Checks whether target belongs between two consecutive values. */
int	belongs_between(int prev, int target, int next)
{
	if (prev > target && target > next)
		return (1);
	if (prev < next && (target < prev || target > next))
		return (1);
	return (0);
}

/* Calculates the shortest rotation direction and distance. */
int	rotation_steps(int pos, int size)
{
	if (size < 2)
		return (0);
	if (pos <= size - pos)
		return (pos);
	return (pos - size);
}

/* Calculates the cost considering simultaneous stack rotations. */
int	combined_cost(int rot_a, int rot_b)
{
	int	a;
	int	b;

	a = abs(rot_a);
	b = abs(rot_b);
	if ((rot_a >= 0 && rot_b >= 0)
		|| (rot_a <= 0 && rot_b <= 0))
	{
		if (a > b)
			return (a);
		return (b);
	}
	return (a + b);
}
