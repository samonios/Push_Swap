/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niesteba <niesteba@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 19:36:25 by niesteba          #+#    #+#             */
/*   Updated: 2026/09/28 20:11:34 by niesteba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (big[i])
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (big[i + j] && little[j]
				&& big[i + j] == little[j] && i + j < len)
				j++;
			if (!little[j])
				return ((char *)&big[i]);
		}
		i++;
	}
	return (0);
}
