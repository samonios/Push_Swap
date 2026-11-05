/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_chunk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalero <svalero@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 17:10:29 by svalero           #+#    #+#             */
/*   Updated: 2026/11/03 19:56:16 by svalero          ###   ########.fr       */
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

	reverse = store->list_size[0] - pos;
	if (pos <= reverse)
	{
		while (pos-- > 0)
			do_op(store, 3);
	}
	else
	{
		while (reverse-- > 0)
			do_op(store, 6);
	}
}

static void	push_target_to_b(t_ab *store, int target)
{
	int	pos;

	pos = find_target_pos(store->stack[0], target);
	rotate_to_top(store, pos);
	do_op(store, 9);
}

void	extract_chunk_from_a(t_ab *store, t_chunk *data, int index)
{
	int	first;
	int	target;
	int	end;

	first = index * data->chunksize;
	end = first + data->tab[index][0];
	target = first;
	while (target < end)
	{
		push_target_to_b(store, target);
		target++;
	}
	data->tab[index][1] = 1;
}
