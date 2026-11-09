/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niesteba <niesteba@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 08:08:22 by svalero           #+#    #+#             */
/*   Updated: 2026/11/09 11:42:33 by niesteba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
