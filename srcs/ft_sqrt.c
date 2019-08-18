/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 16:44:25 by bpace             #+#    #+#             */
/*   Updated: 2019/08/17 23:23:05 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt(int num)
{
	int i;

	i = 1;
	while ((i * i) < num)
		i++;
	return (i);
}

char	**getmap(int mapsize)
{
	int		i;
	int		j;
	char	**map;

	map = (char **)malloc(sizeof(*map) * (mapsize + 1));
	i = -1;
	while (++i < mapsize)
	{
		j = -1;
		map[i] = ft_strnew(mapsize + 1);
		while (++j < mapsize + 1)
		{
			if (j % (mapsize + 1) == mapsize)
				map[i][j] = '\n';
			else
				map[i][j] = '.';
		}
		map[i][j] = '\0';
	}
	map[i] = 0;
	return (map);
}

int		getmapsize(t_coord *pieces)
{
	int		i;
	int		mapsize;

	i = 0;
	while (pieces)
	{
		i++;
		pieces = pieces->next;
	}
	mapsize = ft_sqrt(i * 4);
	return (mapsize);
}

void	freemap(char **map, int mapsize)
{
	int		i;

	i = -1;
	while (++i < mapsize)
	{
		ft_strdel(&map[i]);
		map[i] = 0;
	}
	ft_memdel((void **)&map);
}
