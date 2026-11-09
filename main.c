/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niesteba <niesteba@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 08:08:22 by svalero           #+#    #+#             */
/*   Updated: 2026/11/09 12:40:31 by svalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
