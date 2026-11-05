/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niesteba <niesteba@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 19:43:07 by niesteba          #+#    #+#             */
/*   Updated: 2026/09/27 22:21:10 by niesteba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	char	*res;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	res = malloc((len_s1 + len_s2) * sizeof(char) + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, len_s1 + 1);
	ft_strlcpy(res + len_s1, s2, len_s2 + 1);
	return (res);
}
