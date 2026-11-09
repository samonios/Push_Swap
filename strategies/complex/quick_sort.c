/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niesteba <niesteba@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 18:11:56 by niesteba          #+#    #+#             */
/*   Updated: 2026/11/09 13:03:42 by niesteba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	restore_stack(t_ab *store, int curr_stack, int moved)
{
	int	size;
	int	remaining;

	size = store->list_size[curr_stack];
	if (moved == size)
		return ;
	if (moved <= size / 2)
	{
		while (moved-- > 0)
			do_op(store, 6 + curr_stack);
	}
	else
	{
		remaining = size - moved;
		while (remaining-- > 0)
			do_op(store, 3 + curr_stack);
	}
}

static	int	get_median(t_list *stack, int block_size)
{
	int		min;
	int		max;
	t_data	*content;

	min = INT_MAX;
	max = INT_MIN;
	while (block_size-- > 0)
	{
		content = stack->content;
		if (content->target > max)
			max = content->target;
		if (content->target < min)
			min = content->target;
		stack = stack->next;
	}
	return ((min + max - 1) / 2);
}

static void	separate(t_ab *store, int curr_stack, int size, int *mp)
{
	int	num;
	int	med;

	mp[0] = 0;
	mp[1] = 0;
	mp[2] = 0;
	med = get_median(store->stack[curr_stack], size);
	while (mp[1] < (size + curr_stack) / 2)
	{
		num = ((t_data *)store->stack[curr_stack]->content)->target;
		if (!compare(num, med, curr_stack) && ++mp[0])
			do_op(store, 3 + curr_stack);
		else
		{
			do_op(store, 9 + curr_stack);
			mp[1]++;
			if (!curr_stack && size >= 6 && num < med - (size + 1) / 4)
			{
				mp[2]++;
				if (store->list_size[1] > mp[2])
					do_op(store, 4);
			}
		}
	}
}

void	quick_sort(t_ab *store, int curr_stack, int block_size)
{
	int	mp[3];

	if (block_size <= 3 || is_block_ordered(store, curr_stack, block_size))
	{
		handle_block(store, curr_stack, block_size);
		return ;
	}
	separate(store, curr_stack, block_size, mp);
	if (curr_stack == 0)
	{
		if (block_size - mp[1] != store->list_size[curr_stack])
			restore_stack(store, curr_stack, mp[0]);
		quick_sort(store, curr_stack, block_size - mp[1]);
		quick_sort(store, !curr_stack, mp[1] - mp[2]);
		if (mp[2] != store->list_size[1])
			restore_stack(store, 1, mp[2]);
		quick_sort(store, 1, mp[2]);
	}
	else
	{
		quick_sort(store, 0, mp[1]);
		if (block_size - mp[1] != store->list_size[curr_stack])
			restore_stack(store, curr_stack, mp[0]);
		quick_sort(store, 1, block_size - mp[1]);
	}
}
