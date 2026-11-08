/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalero <svalero@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 19:36:47 by svalero           #+#    #+#             */
/*   Updated: 2026/11/08 19:37:05 by svalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunks.h"

/* Finds the position where target must be inserted in stack B. */
static int	find_successor_pos(t_list *stack, int target, int size)
{
	t_list	*first;
	t_list	*next;
	int		pos;

	if (size < 2)
		return (0);
	first = stack;
	pos = 0;
	while (pos < size)
	{
		next = stack->next;
		if (!next)
			next = first;
		if (belongs_between(((t_data *)stack->content)->target,
				target, ((t_data *)next->content)->target))
			return ((pos + 1) % size);
		stack = stack->next;
		if (!stack)
			stack = first;
		pos++;
	}
	return (0);
}

/* Evaluates an extraction candidate and updates the best move. */
static void	evaluate_extract_move(t_ab *store, t_list *node,
		int pos, t_move *best)
{
	t_move	move;
	int		target;

	target = ((t_data *)node->content)->target;
	move.pos_a = pos;
	move.pos_b = find_successor_pos(store->stack[1], target,
			store->list_size[1]);
	move.rot_a = rotation_steps(move.pos_a, store->list_size[0]);
	move.rot_b = rotation_steps(move.pos_b, store->list_size[1]);
	move.cost = combined_cost(move.rot_a, move.rot_b) + 1;
	if (move.cost < best->cost)
		*best = move;
}

/* Finds the cheapest element to extract from the current chunk. */
int	find_extract_best_move(t_ab *store, int start, int end, t_move *best)
{
	t_list	*node;
	int		pos;
	int		target;

	node = store->stack[0];
	pos = 0;
	best->pos_a = -1;
	best->cost = INT_MAX;
	while (node)
	{
		target = ((t_data *)node->content)->target;
		if (target >= start && target < end)
			evaluate_extract_move(store, node, pos, best);
		node = node->next;
		pos++;
	}
	return (best->cost);
}
