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

#include "../so_long_bonus.h"

int	check_child(char c, t_all *all)
{
	if (c == 'C')
		all->map->c += 1;
	else if (c == 'P')
	{
		all->map->p += 1;
	}
	else if (c == 'E')
		all->map->e += 1;
	else if (c == 'R')
		all->map->r += 1;
	else if (c == '0' || c == '1' || c == '\n')
		return (0);
	else
		return (4);
	return (0);
}

int	check_comp(char *line, t_all *all)
{
	int	i;
	int	l;

	l = ft_strlen(line);
	if (line[0] != '1' || line[l - 2] != '1')
		return (3);
	i = -1;
	while (line[++i])
	{
		if (check_child(line[i], all))
			return (4);
	}
	if (!all->map->h)
		all->map->w = i;
	all->map->h += 1;
	return (0);
}

int	check_char(char *line, t_all *all)
{
	int	error;

	error = check_comp(line, all);
	return (error);
}

int	check_line(char *line, t_all *all)
{
	int	error;

	error = check_char(line, all);
	if (error)
	{
		ft_lstclear(&all->root);
		return (print_error(error));
	}
	else
		ft_lstadd_back(&all->root, ft_lstnew(line));
	return (0);
}

int	print_error(int n)
{
	if (n == 1)
		printf("%s\n", EMPTY_FILE);
	if (n == 2)
		printf("%s\n", NOT_RECTANGULAR);
	if (n == 3)
		printf("%s\n", NOT_ONE);
	if (n == 4)
		printf("%s\n", MORE_COMP);
	if (n == 5)
		printf("%s\n", MISSING);
	return (n);
}
