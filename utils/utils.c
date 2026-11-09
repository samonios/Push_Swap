/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niesteba <niesteba@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 18:53:49 by niesteba          #+#    #+#             */
/*   Updated: 2026/11/09 12:49:05 by svalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	fill_array_op_name(char **name)
{
	name[0] = "sa";
	name[1] = "sb";
	name[2] = "ss";
	name[3] = "ra";
	name[4] = "rb";
	name[5] = "rr";
	name[6] = "rra";
	name[7] = "rrb";
	name[8] = "rrr";
	name[9] = "pb";
	name[10] = "pa";
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
