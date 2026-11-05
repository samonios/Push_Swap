/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalero <svalero@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 20:43:36 by svalero           #+#    #+#             */
/*   Updated: 2026/11/05 09:26:52 by svalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunks.h"

static int	get_target(t_list *stack_a, int offset)
{
	int		i;
	t_list	*node;

	i = 0;
	node = stack_a;
	while (i++ < offset)
		node = node->next;
	return (((t_data *)node->content)->target);
}

static int	get_next_chunk_to_sort(t_ab *store, t_chunk *data)
{
	int	i;
	int	num;

	data->depth = 0;
	while (1)
	{
		if (data->depth % 2 == 0)
			num = get_target(store->stack[0], data->depth / 2);
		else
			num = get_target(store->stack[0], store->list_size[0]
					- (data->depth / 2 + 1));
		i = num / data->chunksize;
		data->tab[i][data->tab[i][2] + data->tab[i][3] + INFO_CHUNK] = num;
		if (data->depth % 2 == 0)
			data->tab[i][2]++;
		else
			data->tab[i][3]++;
		if (data->tab[i][0] == data->tab[i][2] + data->tab[i][3])
			return (i);
		data->depth++;
	}
}

static void	set_to_zero_tab(t_chunk *data, int init)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->chunks)
	{
		j = 2;
		if (init == 0)
			j = 1;
		while (j < (data->tab[i][0] + INFO_CHUNK))
		{
			data->tab[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	sort_by_chunks(t_ab *store)
{
	t_chunk	data;
	int		i;
	int		index;

	if (store->list_size[0] <= 1)
	    return ;
	if (!initialize_data_struct(store->list_size[0], &data))
	{
		is_error(store);
		return ;
	}
	i = 0;
	while (i < data.chunks)
	{
		set_to_zero_tab(&data, i);
		index = get_next_chunk_to_sort(store, &data);
		extract_chunk_from_a(store, &data, index);
		i++;
	}
	return_to_a(store, &data);
	free_array_tab(data.tab, data.chunks);
}
