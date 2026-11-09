/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niesteba <niesteba@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 18:41:50 by svalero           #+#    #+#             */
/*   Updated: 2026/11/09 14:45:38 by niesteba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static long long	count_inversions(t_ab *store)
{
	t_list		*node_i;
	t_list		*node_j;
	t_data		*data_i;
	t_data		*data_j;
	long long	inversions;

	inversions = 0;
	node_i = store->stack[0];
	while (node_i)
	{
		data_i = node_i->content;
		node_j = node_i->next;
		while (node_j)
		{
			data_j = node_j->content;
			if (data_i->target > data_j->target)
				inversions++;
			node_j = node_j->next;
		}
		node_i = node_i->next;
	}
	return (inversions);
}

double	calculate_disorder(t_ab *store)
{
	long long	inversions;
	long long	total_pairs;
	int			size;

	size = store->list_size[0];
	if (size < 2)
		return (0.0);
	inversions = count_inversions(store);
	total_pairs = (long long)size * (size - 1) / 2;
	return ((double)inversions / total_pairs);
}

int	adaptive_sort(t_ab *store, double disorder)
{
	if (store->list_size[0] < 6)
	{
		min_extraction_sort(store);
		if (disorder < 0.2)
			return (1);
		if (disorder < 0.5)
			return (2);
		return (4);
	}
	if (disorder < 0.2)
	{
		min_extraction_sort(store);
		return (1);
	}
	else if (disorder < 0.5)
	{
		sort_by_chunks(store);
		return (2);
	}
	quick_sort(store, 0, store->list_size[0]);
	return (4);
}
