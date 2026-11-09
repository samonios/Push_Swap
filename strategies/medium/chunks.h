/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalero <svalero@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 10:32:39 by svalero           #+#    #+#             */
/*   Updated: 2026/11/09 10:13:36 by svalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHUNKS_H
# define CHUNKS_H

# include "../../push_swap.h"

typedef struct s_chunk
{
	int	nchunks;
	int	csize;
	int	lsize;
}	t_chunk;

typedef struct s_sim
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
	int	cost;
}	t_sim;

typedef struct s_move
{
	int	pos_a;
	int	pos_b;
	int	rot_a;
	int	rot_b;
	int	cost;
}	t_move;

int		index_cheaper_chunk(t_chunk *data, t_ab *store);
int		simulate_extract_chunk(t_ab *store, int start, int capacity);
int		find_sim_best_move(t_sim *sim, int start, int end, t_move *best);
int		sim_positive_pos(int pos, int size);
void	sim_rotate_left(int *array, int size, int pos);
void	sim_remove_top(int *array, int size);
void	sim_push_top(int *array, int *size, int target);
int		find_extract_best_move(t_ab *store, int start, int end, t_move *best);
void	rotate_stacks(t_ab *store, int rot_a, int rot_b);
void	put_chunk_rsorted_b(t_ab *store, t_chunk *data, int index);
void	return_to_a(t_ab *store, t_chunk *data);
int		belongs_between(int prev, int target, int next);
int		rotation_steps(int pos, int size);
int		combined_cost(int rot_a, int rot_b);

#endif
