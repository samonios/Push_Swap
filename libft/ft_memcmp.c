/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niesteba <niesteba@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 19:10:47 by niesteba          #+#    #+#             */
/*   Updated: 2026/09/28 15:50:09 by niesteba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*ss;

	i = 0;
	s = (unsigned char *) s1;
	ss = (unsigned char *) s2;
	while (i < n && s[i] == ss[i])
		i++;
	if (i == n)
		return (0);
	return (s[i] - ss[i]);
}
