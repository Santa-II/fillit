/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 22:40:09 by bpace             #+#    #+#             */
/*   Updated: 2019/08/16 20:42:50 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argv, char **argc)
{
	int	fd;
	int	ans;

	ans = -1;
	if (argv != 2)
	{
		ft_putendl("usage: ./fillit input_file");
		return (ans);
	}
	fd = open(argc[1], O_RDONLY);
	ans = fillit(fd);
	close(fd);
	if (ans == -1)
		ft_putendl("error");
	return (0);
}
