/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niesteba <niesteba@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 18:55:16 by niesteba          #+#    #+#             */
/*   Updated: 2026/09/28 20:08:42 by niesteba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	last;

	i = 0;
	last = -1;
	while (s[i])
	{
		if (s[i] == (char) c)
			last = i;
		i++;
	}
	if ((char) c == '\0')
		last = i;
	if (last != -1)
		return ((char *)&s[last]);
	return (0);
}
