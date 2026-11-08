/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_chunk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalero <svalero@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 19:44:13 by svalero           #+#    #+#             */
/*   Updated: 2026/11/08 19:44:30 by svalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunks.h"

/* Copies the target values from a linked stack into an array. */
static void	copy_stack(t_list *stack, int *array)
{
	int		i;
	t_data	*item;

	i = 0;
	while (stack)
	{
		item = (t_data *)stack->content;
		array[i] = item->target;
		stack = stack->next;
		i++;
	}
}

/* Allocates and initializes the simulation arrays. */
static int	init_simulation(t_sim *sim, t_ab *store)
{
	sim->size_a = store->list_size[0];
	sim->size_b = store->list_size[1];
	sim->a = malloc(sizeof(int) * sim->size_a);
	sim->b = malloc(sizeof(int) * (sim->size_a + sim->size_b));
	if (!sim->a || !sim->b)
	{
		free(sim->a);
		free(sim->b);
		return (0);
	}
	copy_stack(store->stack[0], sim->a);
	copy_stack(store->stack[1], sim->b);
	sim->cost = 0;
	return (1);
}

/* Executes the simulated extraction of the requested chunk. */
static int	run_simulation(t_sim *sim, int start, int capacity)
{
	t_move	move;
	int		n;
	int		target;

	n = 0;
	while (n < capacity && sim->size_a > 0)
	{
		if (!find_sim_best_move(sim, start, start + capacity, &move))
			break ;
		sim->cost += move.cost;
		sim_rotate_left(sim->a, sim->size_a,
			sim_positive_pos(move.rot_a, sim->size_a));
		sim_rotate_left(sim->b, sim->size_b,
			sim_positive_pos(move.rot_b, sim->size_b));
		target = sim->a[0];
		sim_remove_top(sim->a, sim->size_a);
		sim->size_a--;
		sim_push_top(sim->b, &sim->size_b, target);
		n++;
	}
	return (n == capacity);
}

/* Simulates extracting a chunk and returns its total operation cost. */
int	simulate_chunk(t_ab *store, int start, int capacity)
{
	t_sim	sim;
	int		valid;

	if (!init_simulation(&sim, store))
		return (INT_MAX);
	valid = run_simulation(&sim, start, capacity);
	free(sim.a);
	free(sim.b);
	if (!valid)
		return (INT_MAX);
	return (sim.cost);
}
