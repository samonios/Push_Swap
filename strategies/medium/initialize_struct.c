/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalero <svalero@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 10:44:56 by svalero           #+#    #+#             */
/*   Updated: 2026/11/03 19:46:52 by svalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunks.h"

/* The three values are: number of chunks, chunks size, last chunk size*/
static void	assign_three_values(int nb, t_chunk *data)
{
	int	base;
	int	times;

	if (nb < 2)
	{
		data->chunks = nb;
		data->chunksize = nb;
		data->last = nb;
		return ;
	}
	base = 2;
	times = 1;
	while (nb / (base * (times + 1)) >= (base * (times + 1)))
		times++;
	data->chunksize = (base * times);
	data->last = data->chunksize;
	data->chunks = nb / data->chunksize;
	if (nb % data->chunksize != 0)
	{
		data->chunks++;
		data->last = nb % data->chunksize;
	}
}

static int	create_array_tab(t_chunk *data)
{
	int	i;

	data->tab = malloc(sizeof(int *) * data->chunks);
	if (!data->tab)
		return (0);
	i = 0;
	while (i < data->chunks)
	{
		if (i == (data->chunks - 1))
			data->tab[i] = malloc(sizeof(int) * (data->last + INFO_CHUNK));
		else
			data->tab[i] = malloc(sizeof(int) * (data->chunksize + INFO_CHUNK));
		if (!data->tab[i])
		{
			free_array_tab(data->tab, i);
			return (0);
		}
		i++;
	}
	return (1);
}

static void	put_capacity_value(t_chunk *data)
{
	int	i;

	i = 0;
	while (i < (data->chunks - 1))
	{
		data->tab[i][0] = data->chunksize;
		i++;
	}
	data->tab[i][0] = data->last;
}

int	initialize_data_struct(int size_a, t_chunk *data)
{
	assign_three_values(size_a, data);
	if (!create_array_tab(data))
		return (0);
	put_capacity_value(data);
	return (1);
}
