/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niesteba <niesteba@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 19:20:36 by svalero           #+#    #+#             */
/*   Updated: 2026/11/05 12:28:38 by niesteba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	print_disorder(double disorder)
{
	int	value;
	int	decimal;

	value = (int)(disorder * 10000 + 0.5);
	decimal = value % 100;
	ft_putnbr_fd(value / 100, 2);
	write(2, ".", 1);
	if (decimal < 10)
		write(2, "0", 1);
	ft_putnbr_fd(decimal, 2);
	write(2, "%", 1);
}

static int	get_total_operations(t_ab *store)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (i < 11)
	{
		total += store->op_counter[i];
		i++;
	}
	return (total);
}

static void	print_counters(t_ab *store, const int *order, int count)
{
	int	i;

	ft_putstr_fd("[bench] ", 2);
	i = 0;
	while (i < count)
	{
		ft_putstr_fd(store->name[order[i]], 2);
		ft_putstr_fd(": ", 2);
		ft_putnbr_fd(store->op_counter[order[i]], 2);
		if (i < count - 1)
			write(2, " ", 1);
		i++;
	}
	write(2, "\n", 1);
}

void	print_benchmark(t_ab *store, double disorder, char *strategy)
{
	static const int	first[] = {0, 1, 2, 10, 9};
	static const int	second[] = {3, 4, 5, 6, 7, 8};

	ft_putstr_fd("\n[bench] disorder: ", 2);
	print_disorder(disorder);
	ft_putstr_fd("\n[bench] strategy: ", 2);
	ft_putstr_fd(strategy, 2);
	ft_putstr_fd("\n[bench] total_ops: ", 2);
	ft_putnbr_fd(get_total_operations(store), 2);
	write(2, "\n", 1);
	print_counters(store, first, 5);
	print_counters(store, second, 6);
}
