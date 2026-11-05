/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalero <svalero@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 10:32:39 by svalero           #+#    #+#             */
/*   Updated: 2026/11/03 17:51:20 by svalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHUNKS_H
# define CHUNKS_H

# include "../../push_swap.h"

# ifndef INFO_CHUNK
#  define INFO_CHUNK 4
# endif

typedef struct s_chunk
{
	int	chunks;
	int	chunksize;
	int	last;
	int	depth;
	int	**tab;
}	t_chunk;

/*
 * In tab array, for each [i] = chunk;
 *
 * tab[i][0] = chunk capacity;
 * tab[i][1] = sorted (1) or pending (0);
 * tab[i][2] = elements captured from top;
 * tab[i][3] = elements captured from bottom;
 * tab[i][4...] = captured targets, in capture order;
 */
int		initialize_data_struct(int size_a, t_chunk *data);
void	free_array_tab(int **tab, int size);
void	extract_chunk_from_a(t_ab *store, t_chunk *data, int index);
void	return_to_a(t_ab *store, t_chunk *data);
void	free_tab_array(int **tab, int size);

#endif
