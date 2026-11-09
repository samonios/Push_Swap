/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalero <svalero@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 08:08:22 by svalero           #+#    #+#             */
/*   Updated: 2026/11/09 10:47:21 by svalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_array_op_name(char **name)
{
	name[0] = "sa\n";
	name[1] = "sb\n";
	name[2] = "ss\n";
	name[3] = "ra\n";
	name[4] = "rb\n";
	name[5] = "rr\n";
	name[6] = "rra\n";
	name[7] = "rrb\n";
	name[8] = "rrr\n";
	name[9] = "pb\n";
	name[10] = "pa\n";
}

int	main(int ac, char **av)
{
	t_ab	*store;

	if (ac > 1)
	{
		store = ft_calloc(1, sizeof(t_ab));
		if (!store)
			is_error(NULL);
		parser_arg(store, ac, av);
		if (!set_target_position(store))
			is_error(store);
		fill_array_op_name(store->name);
		select_sort_strategy(store);
		free_struct(&store);
	}
	return (0);
}
