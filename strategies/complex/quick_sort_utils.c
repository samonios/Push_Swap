/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niesteba <niesteba@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 19:20:49 by niesteba          #+#    #+#             */
/*   Updated: 2026/10/28 16:24:42 by niesteba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	compare(int a1, int b1, int order)
{
	return (order == (a1 > b1));
}

static int	get_val(t_ab *store, int curr, int index)
{
	t_list	*stack;

	stack = store->stack[curr];
	while (index-- > 0)
		stack = stack->next;
	return (((t_data *)stack->content)->target);
}

static void	sort_3(t_ab *store, int curr)
{
	if (!compare(get_val(store, curr, 0), get_val(store, curr, 1), curr))
		do_op(store, curr);
	if (!compare(get_val(store, curr, 1), get_val(store, curr, 2), curr))
	{
		do_op(store, 3 + curr);
		do_op(store, curr);
		do_op(store, 6 + curr);
		if (!compare(get_val(store, curr, 0), get_val(store, curr, 1), curr))
			do_op(store, curr);
	}
}

void	handle_block(t_ab *store, int curr, int block_size)
{
	if (!is_block_ordered(store, curr, block_size))
	{
		if (block_size == 2)
			do_op(store, curr);
		if (block_size == 3)
			sort_3(store, curr);
	}
	if (curr == 1)
		while (block_size-- > 0)
			do_op(store, 10);
}
