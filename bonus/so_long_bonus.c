/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:09:55 by ajaidi            #+#    #+#             */
/*   Updated: 2022/01/05 18:09:56 by ajaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int ac, char **av)
{
	t_map	map;
	t_list	*root;
	t_all	all;
	t_enemy	enemy;

	root = NULL;
	all.map = &map;
	all.root = root;
	all.enemy = &enemy;
	reset_map(&map);
	if (ac == 2 && check_name(av[1]))
	{
		read_line(av[1], &all);
		render(&all);
	}
}
