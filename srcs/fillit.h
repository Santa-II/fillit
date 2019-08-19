/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 22:37:29 by bpace             #+#    #+#             */
/*   Updated: 2019/08/18 20:50:08 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 546
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct		s_coord
{
	int				col;
	int				row;
	char			letter;
	struct s_coord	*next;
}					t_coord;

int					ft_sqrt(int num);
void				placepieces(t_coord *pieces);
char				**getmap(int mapsize);
void				freemap(char **map, int mapsize);
int					getmapsize(t_coord *pieces);
int					recurse(char **map, t_coord *pieces, int mapsize);
void				assignmapsquares(char **map, int i, int j, t_coord *piece);
void				assignmapbackup(char **map, int i, int j, t_coord *piece);
t_coord				*makepieces(char *buffer, int size);
int					fillit(const int fd);
int					main(int argv, char **argc);
int					checkbuff(int i, int j, t_coord *piece, int mapsize);
int					checkspot(char **map, int i, int j, t_coord *piece);

#endif
