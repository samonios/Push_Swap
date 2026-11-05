/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niesteba <niesteba@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 18:59:26 by niesteba          #+#    #+#             */
/*   Updated: 2026/10/28 16:23:08 by niesteba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	stack_contains(int x, t_ab *store)
{
	t_list	*cursor;
	t_data	*content;

	cursor = store->stack[0];
	while (cursor)
	{
		content = cursor->content;
		if (content->num == x)
			is_error(store);
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
	int		i;
	long	x;
	int		sign;

	i = 0;
	sign = 1;
	x = 0;
	if (arg[j][i] == '-' && ++i)
		sign = -1;
	if (i == 0 && arg[j][i] == '+')
		i++;
	if (!arg[j][i])
		is_error(store);
	while (arg[j][i])
	{
		if (!validate(ft_isdigit(arg[j][i]), arg))
			is_error(store);
		x = x * 10 + (arg[j][i++] - '0');
		if (!validate(!(sign == 1 && x > INT_MAX), arg))
			is_error(store);
		if (!validate(!(sign == -1 && x < INT_MIN), arg))
			is_error(store);
	}
	stack_contains((int)(x * sign), store);
	return ((int)(x * sign));
}
