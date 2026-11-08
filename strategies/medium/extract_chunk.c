/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_chunk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalero <svalero@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 17:10:29 by svalero           #+#    #+#             */
/*   Updated: 2026/11/08 19:41:36 by svalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunks.h"

/* Extracts the selected chunk from A and inserts it in B. */
void	put_chunk_rsorted_b(t_ab *store, t_chunk *data, int index)
{
	int		n;
	int		start;
	int		capacity;
	t_move	move;

	n = 0;
	start = index * data->csize;
	capacity = data->csize;
	if (index == data->nchunks - 1)
		capacity = data->lsize;
	while (n < capacity)
	{
		find_extract_best_move(store, start, start + capacity, &move);
		if (move.pos_a < 0)
			return ;
		rotate_stacks(store, move.rot_a, move.rot_b);
		do_op(store, 9);
		n++;
	}
}
