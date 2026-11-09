/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_strategy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niesteba <niesteba@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 18:33:25 by svalero           #+#    #+#             */
/*   Updated: 2026/11/09 12:25:18 by svalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	execute_strategy(t_ab *store, unsigned char strategy,
	double disorder)
{
	if (store->list_size[0] > 5 && (strategy == 0 || strategy == 8))
		return (adaptive_sort(store, disorder));
	else if (strategy == 1 || store->list_size[0] < 6)
		return(min_extraction_sort(store), 1);
	else if (strategy == 2)
		sort_by_chunks(store);
	else if (strategy == 4)
		quick_sort(store, 0, store->list_size[0]);
	else
		is_error(store);
	return (strategy);
}

static void	set_strategy_info(int strategy, char **name)
{
	if (strategy == 1)
		*name = "Simple / O(n^2)";
	else if (strategy == 2)
		*name = "Medium / O(n * sqrt(n))";
	else if (strategy == 4)
		*name = "Complex / O(n log n)";
}

void	select_sort_strategy(t_ab *store)
{
	unsigned char	strategy;
	double			disorder;
	char			*strategy_name;

	strategy = store->flags & 15;
	disorder = calculate_disorder(store);
	strategy = execute_strategy(store, strategy, disorder);
	set_strategy_info(strategy, &strategy_name);
	if (store->flags & 16)
		print_benchmark(store, disorder, strategy_name);
}
