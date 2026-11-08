/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_rotations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalero <svalero@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 19:40:26 by svalero           #+#    #+#             */
/*   Updated: 2026/11/08 19:40:37 by svalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunks.h"

/* Executes simultaneous rotations in the same direction. */
static void	rotate_combined(t_ab *store, int *rot_a, int *rot_b)
{
	while (*rot_a > 0 && *rot_b > 0)
	{
		do_op(store, 5);
		(*rot_a)--;
		(*rot_b)--;
	}
	while (*rot_a < 0 && *rot_b < 0)
	{
		do_op(store, 8);
		(*rot_a)++;
		(*rot_b)++;
	}
}

/* Executes the remaining rotations on stack A. */
static void	rotate_a(t_ab *store, int rot_a)
{
	while (rot_a > 0)
	{
		do_op(store, 3);
		rot_a--;
	}
	while (rot_a < 0)
	{
		do_op(store, 6);
		rot_a++;
	}
}

/* Executes the remaining rotations on stack B. */
static void	rotate_b(t_ab *store, int rot_b)
{
	while (rot_b > 0)
	{
		do_op(store, 4);
		rot_b--;
	}
	while (rot_b < 0)
	{
		do_op(store, 7);
		rot_b++;
	}
}

/* Executes the required rotations on both stacks. */
void	rotate_stacks(t_ab *store, int rot_a, int rot_b)
{
	rotate_combined(store, &rot_a, &rot_b);
	rotate_a(store, rot_a);
	rotate_b(store, rot_b);
}
