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
	int	l;

	i = -1;
	l = ft_strlen(line);
	if (line[0] == '1' && line[l - 1] == '1' && map->l)
		return (0);
	else
		return (5);
	while (line[++i] && !map->l)
		if (line[i] != '1')
			return (3);
	if (!map->h)
		map->w = i;
	map->l = 1;
	return (0);
}
int	check_child(char c, t_map *map)
{
	if (c == 'C')
		map->c += 1;
	else if (c == 'X')
		map->x += 1;
	else if (c == 'E')
		map->e += 1;
	else if (c == '0' || c == '1')
		return (0);
	else
		return (4);
}

int	check_comp(char *line, t_map *map)
{
	int 	i;

	i = -1;
	while (line[++i])
	{
		if (check_child(line[i], map))
			return (4);
	}
	return (0);
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