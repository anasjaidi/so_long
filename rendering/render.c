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

void	check_xpm(t_map **map, char c, t_mlx *mlx)
{
	int x;
	int y;
	if (c == '1')
	{
		mlx->img = mlx_xpm_file_to_image(mlx->mlx, "wall.xpm", &x, &y );
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, (*map)->x, (*map)->y);
	}
	else if (c == '0')
	{
		mlx->img = mlx_xpm_file_to_image(mlx->mlx, "void.xpm", &x, &y );
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, (*map)->x, (*map)->y);
	}
	else if (c == 'P')
	{
		mlx->img = mlx_xpm_file_to_image(mlx->mlx, "player.xpm", &x, &y );
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, (*map)->x, (*map)->y);
		mlx->px = (*map)->x;
		mlx->py = (*map)->y;
	}
	else if (c == 'E')
	{
		mlx->img = mlx_xpm_file_to_image(mlx->mlx, "exit.xpm", &x, &y );
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, (*map)->x, (*map)->y);
	}
	else if (c == 'C')
	{
		mlx->img = mlx_xpm_file_to_image(mlx->mlx, "col.xpm", &x, &y );
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, (*map)->x, (*map)->y);
	}
	(*map)->x += 40;
}

void	put_map(t_map *map, t_list **root, t_mlx *mlx)
{
	t_list	*ptr;
	char	*line;
	int		i;

	ptr = *root;
	while (ptr)
	{
		i = -1;
		line = ptr->content;
		while (line[++i + 1])
			check_xpm(&map, line[i], mlx);
		map->y += 40;
		map->x = 0;
		ptr = ptr->next;
	}
}

int	render(t_map *map, t_list **root)
{
	t_mlx mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, map->w * 40 - 40, map->h * 40 , "robin");
	put_map(map, root, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}