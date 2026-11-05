/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niesteba <niesteba@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 18:53:49 by niesteba          #+#    #+#             */
/*   Updated: 2026/10/28 17:06:17 by niesteba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_op_name(t_ab *store)
{
	store->name[0] = "sa";
	store->name[1] = "sb";
	store->name[2] = "ss";
	store->name[3] = "ra";
	store->name[4] = "rb";
	store->name[5] = "rr";
	store->name[6] = "rra";
	store->name[7] = "rrb";
	store->name[8] = "rrr";
	store->name[9] = "pb";
	store->name[10] = "pa";
}

int	is_block_ordered(t_ab *store, int curr, int block_size)
{
	t_list	*cursor;
	int		i;

	if (block_size == 1)
		return (1);
	i = 0;
	cursor = store->stack[curr];
	while (i < block_size - 1)
	{
		if (!compare(((t_data *)cursor->content)->target,
			((t_data *)cursor->next->content)->target, curr))
			return (0);
		cursor = cursor->next;
		i++;
	}
	return (1);
}