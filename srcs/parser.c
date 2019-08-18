/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 21:18:23 by bpace             #+#    #+#             */
/*   Updated: 2019/08/17 23:22:16 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			checkconnections(char *str, int i, int connect)
{
	if (i > 0)
		if (str[i - 1] && str[i - 1] == '#')
			connect++;
	if (i > 4)
		if (str[i - 5] && str[i - 5] == '#')
			connect++;
	if (i < 15)
		if (str[i + 5] && str[i + 5] == '#')
			connect++;
	if (i < 19)
		if (str[i + 1] && str[i + 1] == '#')
			connect++;
	return (connect);
}

t_coord		*maketetra(char *buf, char c)
{
	int		i;
	int		nos;
	int		connect;
	t_coord	*ans;

	i = -1;
	nos = 0;
	connect = 0;
	if (!(ans = malloc(sizeof(t_coord) * 4)))
		return (NULL);
	while (++i < 20)
		if (buf[i] == '#')
		{
			if (nos == 4)
				return (NULL);
			ans[nos].col = i % 5;
			ans[nos].row = i / 5;
			nos++;
			connect = checkconnections(buf, i, connect);
		}
	ans->letter = c;
	if (connect != 6 && connect != 8)
		return (NULL);
	return (ans);
}

t_coord		*makepieces(char *buffer, int len)
{
	t_coord	*pieces;
	int		i;
	char	c;
	t_coord	*head;

	c = 'A';
	if (!(pieces = maketetra(buffer, c)))
		return (NULL);
	head = pieces;
	i = 21;
	while (i < len)
	{
		c++;
		if (!(pieces->next = maketetra(buffer + i, c)))
			return (NULL);
		pieces = pieces->next;
		i = i + 21;
	}
	pieces->next = NULL;
	return (head);
}
