/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:00:15 by ajaidi            #+#    #+#             */
/*   Updated: 2022/01/11 17:00:56 by ajaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	check_xpm(char c, t_all *all)
{
	int	x;
	int	y;

	if (c == '1')
		put_wall(all, &x, &y);
	else if (c == '0')
		put_empty(all, &x, &y);
	else if (c == 'P')
		put_player(all, &x, &y);
	else if (c == 'E')
		put_exit(all, &x, &y);
	else if (c == 'R')
		put_enemy(all, &x, &y);
	else if (c == 'C')
		put_collect(all, &x, &y);
	all->map->x += 30;
}

void	check_line2(t_all *all, char *line)
{
	int		i;

	i = -1;
	while (line[++i])
		check_xpm(line[i], all);
	all->map->y += 30;
	all->map->x = 0;
}

int	put_map(t_all *all)
{
	t_list	*ptr;
	char	*line;

	ptr = all->root;
	all->map->y = 0;
	all->map->x = 0;
	all->enemy->i = 0;
	while (ptr->next)
	{
		line = ptr->content;
		check_line2(all, line);
		ptr = ptr->next;
	}
	return (0);
}

int	dest(t_all *all)
{
	mlx_destroy_window(all->mlx->mlx, all->mlx->win);
	exit(0);
	return (0);
}

int	render(t_all *all)
{
	t_mlx	mlx;

	all->mlx = &mlx;
	all->mlx->mlx = mlx_init();
	all->mlx->win = mlx_new_window(all->mlx->mlx, all->map->w * 30 - 30,
			all->map->h * 30, "robin");
	put_map(all);
	mlx_hook(all->mlx->win, 2, 0, key_hook, all);
	mlx_hook(all->mlx->win, 17, 0, dest, all);
	mlx_loop_hook(all->mlx->mlx, anime, all);
	mlx_loop(all->mlx->mlx);
	return (0);
}
