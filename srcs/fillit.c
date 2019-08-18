/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 16:43:40 by bpace             #+#    #+#             */
/*   Updated: 2019/08/16 22:23:20 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*stupidnormline(char *buffer, int i)
{
	if ((i + 1) % 21 != 0)
		return (NULL);
	return (buffer);
}

char	*returnmap(char *buffer)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (buffer[i])
	{
		j = -1;
		while (buffer[i] && ++j < 4)
		{
			k = -1;
			while (buffer[i] && ++k < 4)
			{
				if (buffer[i] != '.' && buffer[i] != '#')
					return (NULL);
				i++;
			}
			if (buffer[i] && buffer[i++] != '\n')
				return (NULL);
		}
		if (buffer[i] && buffer[i++] != '\n')
			return (NULL);
	}
	return (stupidnormline(buffer, i));
}

void	free_piece(t_coord *pieces)
{
	t_coord	*temp;

	while (pieces)
	{
		temp = pieces;
		pieces = pieces->next;
		free(temp);
	}
}

int		fillit(const int fd)
{
	char	buffer[BUFF_SIZE];
	t_coord	*pieces;
	int		reader;

	if (fd < 0 || (reader = read(fd, buffer, BUFF_SIZE)) < 0)
		return (-1);
	if (reader > 545 || reader < 20)
		return (-1);
	buffer[reader] = '\0';
	if (!returnmap(buffer))
		return (-1);
	if (!(pieces = makepieces(buffer, reader)))
		return (-1);
	placepieces(pieces);
	free_piece(pieces);
	return (0);
}
