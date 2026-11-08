/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalero <svalero@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 17:05:57 by svalero           #+#    #+#             */
/*   Updated: 2026/11/08 18:08:06 by svalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunks.h"

/* Finds the position of a target value in a stack. */
static int	find_target_pos(t_list *stack, int target)
{
	int		pos;
	t_data	*item;

	pos = 0;
	while (stack)
	{
		item = (t_data *)stack->content;
		if (item->target == target)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

/* Rotates stack B to place the requested position on top. */
static void	rotate_to_top(t_ab *store, int pos)
{
	int	reverse;

	reverse = store->list_size[1] - pos;
	if (pos <= reverse)
	{
		while (pos-- > 0)
			do_op(store, 4);
	}
	else
	{
		while (reverse-- > 0)
			do_op(store, 7);
	}
}

/* Pushes all values from one chunk back to stack A. */
static void	push_chunk_to_a(t_ab *store, t_chunk *data, int index)
{
	int	target;
	int	end;
	int	pos;
	int	capacity;

	capacity = data->csize;
	if (index == data->nchunks - 1)
		capacity = data->lsize;
	target = index * data->csize + capacity - 1;
	end = index * data->csize;
	while (target >= end)
	{
		pos = find_target_pos(store->stack[1], target);
		rotate_to_top(store, pos);
		do_op(store, 10);
		target--;
	}
}

/* Returns all elements from B to A in ascending target order. */
void	return_to_a(t_ab *store, t_chunk *data)
{
	int	index;

	index = data->nchunks - 1;
	while (index >= 0)
	{
		push_chunk_to_a(store, data, index);
		index--;
	}
}
