/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_strategy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalero <svalero@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 18:33:25 by svalero           #+#    #+#             */
/*   Updated: 2026/11/03 19:39:44 by svalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	execute_strategy(t_ab *store, unsigned char strategy,
	double disorder)
{
	if (strategy == 0 || strategy == 8)
		return (adaptive_sort(store, disorder));
	else if (strategy == 1)
		min_extraction_sort(store);
	else if (strategy == 2)
		sort_by_chunks(store);
	else if (strategy == 4)
		quick_sort(store, 0, store->list_size[0]);
	else
		is_error(store);
	return (strategy);
}

static void	set_strategy_info(int strategy, char **name,
	char **complexity)
{
	if (strategy == 1)
	{
		*name = "Simple";
		*complexity = "O(n^2)";
	}
	else if (strategy == 2)
	{
		*name = "Medium";
		*complexity = "O(n * sqrt(n))";
	}
	else if (strategy == 4)
	{
		*name = "Complex";
		*complexity = "O(n log n)";
	}
}

void	select_sort_strategy(t_ab *store)
{
	unsigned char	strategy;
	double			disorder;
	char			*strategy_name;
	char			*complexity;

	strategy = store->flags & 15;
	disorder = 0.0;
	if (strategy == 0 || strategy == 8 || (store->flags & 16))
		disorder = calculate_disorder(store);
	strategy = execute_strategy(store, strategy, disorder);
	set_strategy_info(strategy, &strategy_name, &complexity);
	if (store->flags & 16)
		print_benchmark(store, disorder, strategy_name, complexity);
}
