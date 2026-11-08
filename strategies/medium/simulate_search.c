/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_search.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalero <svalero@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 19:21:54 by svalero           #+#    #+#             */
/*   Updated: 2026/11/08 19:22:18 by svalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunks.h"

/* Finds the position where target must be inserted in stack B. */
static int	find_successor(int *b, int size, int target)
{
	int	i;
	int	next;

	if (size < 2)
		return (0);
	i = 0;
	while (i < size)
	{
		next = (i + 1) % size;
		if (belongs_between(b[i], target, b[next]))
			return (next);
		i++;
	}
	return (0);
}

/* Evaluates a candidate element and updates the best move. */
static void	evaluate_sim_move(t_sim *sim, int pos, t_move *best)
{
	int	pos_b;
	int	rot_a;
	int	rot_b;
	int	cost;

	pos_b = find_successor(sim->b, sim->size_b, sim->a[pos]);
	rot_a = rotation_steps(pos, sim->size_a);
	rot_b = rotation_steps(pos_b, sim->size_b);
	cost = combined_cost(rot_a, rot_b) + 1;
	if (cost < best->cost)
	{
		best->pos_a = pos;
		best->pos_b = pos_b;
		best->rot_a = rot_a;
		best->rot_b = rot_b;
		best->cost = cost;
	}
}

/* Finds the cheapest element to extract from the simulated chunk. */
int	find_sim_best_move(t_sim *sim, int start, int end, t_move *best)
{
	int	i;

	i = 0;
	best->cost = INT_MAX;
	while (i < sim->size_a)
	{
		if (sim->a[i] >= start && sim->a[i] < end)
			evaluate_sim_move(sim, i, best);
		i++;
	}
	if (best->cost == INT_MAX)
		return (0);
	return (1);
}
