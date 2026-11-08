/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_chunk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalero <svalero@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 14:23:07 by svalero           #+#    #+#             */
/*   Updated: 2026/11/08 19:45:10 by svalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunks.h"

/* Selects the chunk with the lowest simulated extraction cost. */
int	index_cheaper_chunk(t_chunk *data, t_ab *store)
{
	int	i;
	int	cost;
	int	lower;
	int	index;
	int	capacity;

	i = 0;
	lower = INT_MAX;
	index = -1;
	while (i < data->nchunks)
	{
		capacity = data->csize;
		if (i == data->nchunks - 1)
			capacity = data->lsize;
		cost = simulate_chunk(store, i * data->csize, capacity);
		if (cost < lower)
		{
			lower = cost;
			index = i;
		}
		i++;
	}
	return (index);
}
