/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niesteba <niesteba@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:29:56 by niesteba          #+#    #+#             */
/*   Updated: 2026/11/09 11:42:06 by niesteba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_op_code(t_ab *store, char *op)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		if (!ft_strncmp(op, store->name[i], ft_strlen(store->name[i])))
			return (i);
		i++;
	}
	return (-1);
}

void	check(t_ab *store)
{
	if (store->list_size[1] != 0
		|| !is_block_ordered(store, 0, store->list_size[0]))
		write(2, "KO", 2);
	else
		write(1, "OK", 2);
}

int	main(int ac, char **av)
{
	t_ab	*store;
	char	*op;
	int		op_code;

	store = calloc(1, sizeof(t_ab));
	if (!store)
		return (-1);
	parser_arg(store, ac, av);
	if (store->flags != 0)
		is_error(store);
	op = get_next_line(0);
	fill_array_op_name(store->name);
	store->flags = 32;
	while (op)
	{
		op_code = get_op_code(store, op);
		do_op(store, op_code);
		free(op);
		if (op_code == -1)
			is_error(store);
		op = get_next_line(0);
	}
	check(store);
	free_struct(&store);
}
