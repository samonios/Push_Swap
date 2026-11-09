/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niesteba <niesteba@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 18:50:18 by niesteba          #+#    #+#             */
/*   Updated: 2026/11/09 13:56:13 by niesteba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "libft/libft.h"

typedef struct s_data
{
	int		num;
	int		target;
}	t_data;

typedef struct s_ab
{
	unsigned char	flags;
	int				input_size;
	int				list_size[2];
	int				op_counter[11];
	char			*name[11];
	t_list			*stack[2];
}	t_ab;

void	free_arg(char **arg);
void	is_error(t_ab *store);
void	do_swap(t_list **stack);
void	do_rotate(t_list **stack);
void	free_struct(t_ab **store);
void	do_op(t_ab *store, int op);
void	sort_by_chunks(t_ab *store);
void	do_r_rotate(t_list **stack);
void	fill_array_op_name(char **name);
void	min_extraction_sort(t_ab *store);
void	select_sort_strategy(t_ab *store);
void	parser_arg(t_ab *store, int ac, char **av);
void	quick_sort(t_ab *store, int curr, int block_size);
void	handle_block(t_ab *store, int curr, int block_size);
void	print_benchmark(t_ab *store, double disorder, char *strategy);
void	do_push(t_list **src, t_list **dst, int *size_dst, int *size_src);

int		ft_strcmp(char *s1, char *s2);
int		set_target_position(t_ab *store);
int		compare(int a1, int b1, int order);
int		check_flags(char *arg, t_ab *store);
int		adaptive_sort(t_ab *store, double disorder);
int		atoi_and_valid(char **arg, int j, t_ab *store);
int		is_block_ordered(t_ab *store, int curr, int block_size);

double	calculate_disorder(t_ab *store);

#endif
