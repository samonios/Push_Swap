/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niesteba <niesteba@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 12:15:16 by niesteba          #+#    #+#             */
/*   Updated: 2026/09/27 22:20:39 by niesteba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_n_digits(int nb)
{
	int	n_digits;

	n_digits = 1;
	while (nb / 10 != 0)
	{
		nb /= 10;
		n_digits++;
	}
	return (n_digits);
}

static	void	fill_res(long n_l, int i, char *res)
{
	if (n_l < 0)
	{
		res[0] = '-';
		n_l = -n_l;
	}
	if (n_l >= 10)
		fill_res(n_l / 10, i - 1, res);
	res[i] = (n_l % 10) + '0';
}

char	*ft_itoa(int n)
{
	int		n_dig;
	char	*res;

	n_dig = get_n_digits(n);
	res = (char *)malloc((n_dig + 1 + (n < 0)) * sizeof(char));
	if (!res)
		return (NULL);
	fill_res(n, n_dig - 1 + (n < 0), res);
	res[n_dig + (n < 0)] = '\0';
	return (res);
}
