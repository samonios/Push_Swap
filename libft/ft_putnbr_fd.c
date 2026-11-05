/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niesteba <niesteba@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 12:42:42 by niesteba          #+#    #+#             */
/*   Updated: 2026/09/28 15:03:04 by niesteba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	n_l;
	char	c;

	n_l = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		n_l = -n_l;
	}
	if (n_l >= 10)
		ft_putnbr_fd(n_l / 10, fd);
	c = (n_l % 10) + '0';
	write(fd, &c, 1);
}
