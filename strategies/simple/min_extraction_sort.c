/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_extraction_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niesteba <niesteba@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 13:05:46 by niesteba          #+#    #+#             */
/*   Updated: 2026/11/09 12:30:25 by niesteba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_list	*search_min(t_list *cursor, int *min_index)
{
	t_list	*min_node;
	t_data	*content;
	int		min;
	int		count;

	count = 0;
	content = cursor->content;
	min_node = cursor;
	min = content->num;
	while (cursor)
	{
		content = cursor->content;
		if (content->num < min)
		{
			min_node = cursor;
			min = content->num;
			*min_index = count;
		}
		count++;
		cursor = cursor->next;
	}
	return (min_node);
}

void	move_to_head(t_ab *store, t_list *min_node, int direction)
{
	while (min_node != store->stack[0])
		do_op(store, 3 * (!direction + 1));
}

void	restock_a(t_ab *store)
{
	while (store->list_size[1] > 0)
		do_op(store, 10);
}

void	min_extraction_sort(t_ab *store)
{
	t_list	*min_node;
	int		min_index;

	while (store->list_size[0] > 1
		&& !is_block_ordered(store, 0, store->list_size[0]))
	{
		min_index = 0;
		min_node = search_min(store->stack[0], &min_index);
		move_to_head(store, min_node, min_index <= store->list_size[0] / 2);
		do_op(store, 9);
	}
	restock_a(store);
}
