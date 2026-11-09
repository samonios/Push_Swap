/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niesteba <niesteba@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 18:59:26 by niesteba          #+#    #+#             */
/*   Updated: 2026/11/09 13:46:57 by niesteba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	stack_contains(int x, t_ab *store, char **arg)
{
	t_list	*cursor;
	t_data	*content;

	cursor = store->stack[0];
	while (cursor)
	{
		content = cursor->content;
		if (content->num == x)
		{
			free_arg(arg);
			is_error(store);
		}
		cursor = cursor->next;
	}
}

static int	validate(int condition, char **arg)
{
	if (!condition)
		return (free_arg(arg), 0);
	return (1);
}

int	atoi_and_valid(char **arg, int j, t_ab *store)
{
	size_t		i;
	long		x;
	int			sign;

	i = 0;
	sign = 1;
	x = 0;
	if (arg[j][i] == '-' && ++i)
		sign = -1;
	if (i == 0 && arg[j][i] == '+')
		i++;
	if (!validate(arg[j][i], arg))
		is_error(store);
	while (arg[j][i])
	{
		if (!validate(ft_isdigit(arg[j][i]), arg))
			is_error(store);
		x = x * 10 + (arg[j][i++] - '0');
		if (!validate(!(sign == 1 && x > INT_MAX), arg))
			is_error(store);
		if (!validate(!(sign == -1 && x > INT_MIN + 1), arg))
			is_error(store);
	}
	stack_contains((int)(x * sign), store, arg);
	return ((int)(x * sign));
}
