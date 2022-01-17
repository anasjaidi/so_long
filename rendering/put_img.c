/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:04:07 by ajaidi            #+#    #+#             */
/*   Updated: 2022/01/11 13:41:42 by ajaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_wall(t_all *all, int *x, int *y)
{
	all->mlx->img = mlx_xpm_file_to_image(all->mlx->mlx, "xpm/1.xpm", x, y);
	mlx_put_image_to_window(all->mlx->mlx, all->mlx->win, all->mlx->img,
		all->map->x, all->map->y);
}

void	put_collect(t_all *all, int *x, int *y)
{
	all->mlx->img = mlx_xpm_file_to_image(all->mlx->mlx, "xpm/c.xpm", x, y);
	mlx_put_image_to_window(all->mlx->mlx, all->mlx->win, all->mlx->img,
		all->map->x, all->map->y);
}

void	put_player(t_all *all, int *x, int *y)
{
	all->mlx->img = mlx_xpm_file_to_image(all->mlx->mlx, "xpm/p.xpm", x, y);
	mlx_put_image_to_window(all->mlx->mlx, all->mlx->win, all->mlx->img,
		all->map->x, all->map->y);
	all->mlx->px = all->map->x / 30 + 1;
	all->mlx->py = all->map->y / 30 + 1;
}

void	put_exit(t_all *all, int *x, int *y)
{
	all->mlx->img = mlx_xpm_file_to_image(all->mlx->mlx, "xpm/e.xpm", x, y);
	mlx_put_image_to_window(all->mlx->mlx, all->mlx->win, all->mlx->img,
		all->map->x, all->map->y);
}

void	put_empty(t_all *all, int *x, int *y)
{
	all->mlx->img = mlx_xpm_file_to_image(all->mlx->mlx, "xpm/0.xpm", x, y);
	mlx_put_image_to_window(all->mlx->mlx, all->mlx->win, all->mlx->img,
		all->map->x, all->map->y);
}
