/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalero <svalero@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 20:43:36 by svalero           #+#    #+#             */
/*   Updated: 2026/11/09 12:09:40 by svalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunks.h"

/* Calculates the optimal chunk size for more than 12 elements. */
static int	get_chunk_size(int size_a)
{
	int	csize;
	
	csize = 0;
	while (size_a / (csize + 1) >= (csize + 1))
		csize++;
	return (csize * 3 + csize / 3);
}

/* Initializes the number and capacity of the chunks. */
static void	set_chunk_data(t_chunk *data, int size_a)
{
	data->csize = get_chunk_size(size_a);
	if (data->csize > size_a / 2)
		data->csize = size_a / 2;
	if (data->csize < 1)
		data->csize = 1;
	data->nchunks = size_a / data->csize;
	data->lsize = size_a % data->csize;
	if (data->lsize != 0)
		data->nchunks++;
	else
		data->lsize = data->csize;
}

/* Sorts stack A by extracting the cheapest chunk into stack B. */
void	sort_by_chunks(t_ab *store)
{
	t_chunk	data;
	int		n;
	int		index;

	if (store->list_size[0] < 2 && is_block_ordered(store, 0, store->list_size[0]))
		return ;
	set_chunk_data(&data, store->list_size[0]);
	n = 0;
	while (n < data.nchunks)
	{
		index = index_cheaper_chunk(&data, store);
		put_chunk_rsorted_b(store, &data, index);
		n++;
	}
	return_to_a(store, &data);
}
