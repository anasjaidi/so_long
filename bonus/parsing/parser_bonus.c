/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:56:18 by ajaidi            #+#    #+#             */
/*   Updated: 2022/01/11 11:58:35 by ajaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	check_one1(char *line1)
{
	int	i;

	i = 0;
	while (line1[i + 1])
	{
		if (line1[i] != '1')
			return (print_error(3));
		i++;
	}
	return (0);
}

int	check_one2(char *line1)
{
	int	i;

	i = 0;
	while (line1[i])
	{
		if (line1[i] != '1')
			return (print_error(3));
		i++;
	}
	return (0);
}

int	check_map(t_map *map, t_list **root)
{
	int	y;
	int	x;

	if (!map->c || !map->e || !map->p)
		return (print_error(5));
	x = check_one1((*root)->content);
	y = check_one2(ft_lstlast(*root)->content);
	if (x || y)
		return (3);
	return (0);
}

char	*read_line(char *path, t_all *all)
{
	char	*line;
	int		fd;
	int		error;

	fd = open(path, O_RDWR);
	line = get_next_line(fd);
	all->root = NULL;
	if (!line)
		print_error(1);
	while (line)
	{
		error = check_line(line, all);
		if (error)
			exit(0);
		line = get_next_line(fd);
	}
	if (check_map(all->map, &all->root))
		exit(0);
	return (NULL);
}
