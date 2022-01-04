/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 19:30:00 by ajaidi            #+#    #+#             */
/*   Updated: 2022/01/04 19:30:01 by ajaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../so_long.h"

int check_one(char *line, t_map *map)
{
	int	i;

	i = -1;
	while (line[++i])
		if (line[i] != '1')
			return (3);
	if (!map->h)
		map->w = i;
	return (0);
}

int	check_comp(char *line, t_map *map)
{
	int 	i;
	int 	j;
	int		l;
	char	*comp;

	i = -1;
	j = -1;
	comp = "10EXC";
	l = ft_strlen(line);
	if ()
	while (line[++i])
	{
		j = -1;
		while (comp[++j])
			if (!comp[j + 1] && line[i] != comp[j])
				return (4);
	}
}

int	check_char(char *line, t_map *map)
{
	int	error;


	if (!map->h)
		error = check_one(line, map);
	
	if (!error)
		free_map(line, 3);
}


int	check_line(char *line, t_map *map)
{
	int	error;
	error = check_char(line, map);
}