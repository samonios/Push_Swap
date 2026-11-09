/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalero <svalero@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:29:56 by niesteba          #+#    #+#             */
/*   Updated: 2026/11/09 16:37:57 by svalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_op_code(t_ab *store, char *op)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		if (!ft_strncmp(op, store->name[i], ft_strlen(store->name[i]))
			&& op[ft_strlen(store->name[i])] == '\n'
			&& ft_strlen(op) == ft_strlen(store->name[i]) + 1)
			return (i);
		i++;
	}
	return (-1);
}

void	check(t_ab *store)
{
	if (store->list_size[1] != 0
		|| !is_block_ordered(store, 0, store->list_size[0]))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

int	main(int ac, char **av)
{
	t_ab	*store;
	char	*op;
	int		op_code;

	store = calloc(1, sizeof(t_ab));
	if (!store)
		return (2);
	parser_arg(store, ac, av);
	if (store->list_size[0] == 0)
		return (1);
	if (store->flags != 0)
		is_error(store);
	op = get_next_line(0);
	fill_array_op_name(store->name);
	set_target_position(store);
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
	return (check(store), free_struct(&store), 0);
}
