/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalero <svalero@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 17:05:57 by svalero           #+#    #+#             */
/*   Updated: 2026/11/03 20:01:07 by svalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunks.h"

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

static void	push_chunk_to_a(t_ab *store, t_chunk *data, int index)
{
	int	target;
	int	end;
	int	pos;

	target = index * data->chunksize + data->tab[index][0] - 1;
	end = index * data->chunksize;
	while (target >= end)
	{
		pos = find_target_pos(store->stack[1], target);
		rotate_to_top(store, pos);
		do_op(store, 10);
		target--;
	}
}

void	return_to_a(t_ab *store, t_chunk *data)
{
	int	index;

	index = data->chunks - 1;
	while (index >= 0)
	{
		push_chunk_to_a(store, data, index);
		index--;
	}
}
