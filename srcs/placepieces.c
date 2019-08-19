/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placepieces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:50:57 by bpace             #+#    #+#             */
/*   Updated: 2019/08/18 20:51:48 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		checkspot(char **map, int i, int j, t_coord *piece)
{
	int		co;
	int		ro;
	int		squ;
	int		count;

	squ = -1;
	count = 0;
	while (++squ < 4)
	{
		co = j + piece[squ].col - piece[0].col;
		ro = i + piece[squ].row - piece[0].row;
		if (!(map[ro][co] && map[ro][co] == '.'))
			return (0);
		count++;
	}
	if (count != 4)
		return (0);
	return (1);
}

void	assignmapsquares(char **map, int i, int j, t_coord *piece)
{
	int		co;
	int		ro;
	int		squ;

	squ = -1;
	while (++squ < 4)
	{
		co = j + piece[squ].col - piece[0].col;
		ro = i + piece[squ].row - piece[0].row;
		map[ro][co] = piece->letter;
	}
}

void	assignmapbackup(char **map, int i, int j, t_coord *piece)
{
	int		co;
	int		ro;
	int		squ;

	squ = -1;
	while (++squ < 4)
	{
		co = j + piece[squ].col - piece[0].col;
		ro = i + piece[squ].row - piece[0].row;
		map[ro][co] = '.';
	}
}

int		recurse(char **map, t_coord *pieces, int mapsize)
{
	int		i;
	int		j;

	if (!pieces)
		return (1);
	i = -1;
	while (map[++i] != 0)
	{
		j = -1;
		while (map[i][++j] != '\0')
			if (map[i][j] != '\n')
				if (checkbuff(i, j, pieces, mapsize))
					if (checkspot(map, i, j, pieces))
					{
						assignmapsquares(map, i, j, pieces);
						if (recurse(map, pieces->next, mapsize))
							return (1);
						else
							assignmapbackup(map, i, j, pieces);
					}
	}
	return (0);
}

void	placepieces(t_coord *pieces)
{
	char	**map;
	int		mapsize;
	int		i;

	mapsize = getmapsize(pieces);
	map = getmap(mapsize);
	while (!(recurse(map, pieces, mapsize)))
	{
		freemap(map, mapsize);
		mapsize++;
		map = getmap(mapsize);
	}
	i = -1;
	while (map[++i])
		ft_putstr(map[i]);
	freemap(map, mapsize);
}
