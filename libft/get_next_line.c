/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niesteba <niesteba@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 19:28:44 by niesteba          #+#    #+#             */
/*   Updated: 2026/10/05 11:11:14 by niesteba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	split_line(char *block, char **stash, ssize_t eol, ssize_t nread)
{
	*stash = NULL;
	if (nread - eol > 1)
	{
		*stash = (char *) malloc((nread - eol) * sizeof(char));
		if (!(*stash))
			return (0);
		ft_strlcpy(*stash, &block[eol + 1], nread - eol);
	}
	block[eol + 1] = '\0';
	return (1);
}

static void	read_blocks(char **stash, char *block, int fd, char **linea)
{
	ssize_t	nread;
	ssize_t	eol;

	eol = -1;
	nread = 1;
	while (nread > 0 && eol == -1)
	{
		nread = read(fd, block, BUFFER_SIZE);
		if (nread <= 0)
			break ;
		block[nread] = '\0';
		eol = get_end_line(block, nread);
		if (eol != -1 && !split_line(block, stash, eol, nread))
			nread = -1;
		else if (eol != -1)
			nread = eol + 1;
		if (nread == -1 || !add_to_line(linea, block, nread))
			break ;
	}
	if (nread == -1)
	{
		free(*linea);
		*linea = NULL;
	}
}

static ssize_t	handle_stash(char **linea, char **stash)
{
	ssize_t	eol_stash;

	eol_stash = get_end_line(*stash, -1);
	*linea = *stash;
	if (eol_stash == -1)
		*stash = NULL;
	else if (!split_line(*linea, stash, eol_stash, (ssize_t)ft_strlen(*stash)))
	{
		free(*linea);
		*linea = NULL;
	}
	return (eol_stash);
}

char	*get_next_line(int fd)
{
	static char		*stash = NULL;
	char			*linea;
	char			*block;	

	linea = NULL;
	if (stash && handle_stash(&linea, &stash) != -1)
		return (linea);
	block = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!block)
		return (free(linea), NULL);
	read_blocks(&stash, block, fd, &linea);
	if (!linea)
	{
		free(stash);
		stash = NULL;
	}
	return (free(block), linea);
}
