/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:00:15 by ajaidi            #+#    #+#             */
/*   Updated: 2022/01/06 12:00:44 by ajaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_xpm(char c, t_all *all, int i, int j)
{
	int x;
	int y;
	if (c == '1')
	{
		all->mlx->img = mlx_xpm_file_to_image(all->mlx->mlx, "1.xpm", &x, &y );
		mlx_put_image_to_window(all->mlx->mlx, all->mlx->win, all->mlx->img, all->map->x, all->map->y);
	}
	else if (c == '0')
	{
		all->mlx->img = mlx_xpm_file_to_image(all->mlx->mlx, "0.xpm", &x, &y );
		mlx_put_image_to_window(all->mlx->mlx, all->mlx->win, all->mlx->img, all->map->x, all->map->y);
	}
	else if (c == 'P')
	{
		all->mlx->img = mlx_xpm_file_to_image(all->mlx->mlx, "P.xpm", &x, &y );
		mlx_put_image_to_window(all->mlx->mlx, all->mlx->win, all->mlx->img, all->map->x, all->map->y);
		all->mlx->px = all->map->x / 40 + 1;
		all->mlx->py = all->map->y / 40 + 1;
	}
	else if (c == 'E')
	{
		all->mlx->img = mlx_xpm_file_to_image(all->mlx->mlx, "E.xpm", &x, &y );
		mlx_put_image_to_window(all->mlx->mlx, all->mlx->win, all->mlx->img, all->map->x, all->map->y);
	}
	else if (c == 'C')
	{
		all->mlx->img = mlx_xpm_file_to_image(all->mlx->mlx, "C.xpm", &x, &y );
		mlx_put_image_to_window(all->mlx->mlx, all->mlx->win, all->mlx->img, all->map->x, all->map->y);
	}
	all->map->x += 40;
}

void	put_map(t_all *all)
{
	t_list	*ptr;
	char	*line;
	int		i;
	int 	j;

	ptr = all->root;
	all->map->y = 0;
	all->map->x = 0;
	j = 1;
	while (ptr)
	{
		i = -1;
		line = ptr->content;
		while (line[++i + 1])
			check_xpm(line[i], all, i , j);
		all->map->y += 40;
		all->map->x = 0;
		ptr = ptr->next;
		j++;
	}
}

// int dest(t_all *all)
// {
// 	mlx_destroy_window(all->mlx->mlx, all->mlx->win);
// 	exit(0);
// 	return (0);
// }

int	render(t_all *all)
{
	t_mlx mlx;

	all->mlx = &mlx;
	all->mlx->mlx= mlx_init();
	all->mlx->win = mlx_new_window(all->mlx->mlx, all->map->w * 40 - 40, all->map->h * 40 , "robin");
	put_map(all);
	mlx_hook(all->mlx->win, 2, 0, key_hook, all);
	//mlx_hook(all->mlx->win, 18, 0, dest, all);
	mlx_loop(all->mlx->mlx);
	return (0);
}