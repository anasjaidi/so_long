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

void	check_xpm(t_map **map, char c)
{
	void	*img;

	img = mlx_xpm_file_to_image()
}

void	put_map(t_map *map, t_list **root)
{
	t_list	*ptr;
	char	*line;
	int		i;

	ptr = *root;
	while (ptr)
	{
		i = -1;
		line = ptr->content;
		while (line[++i])
			check_xpm(map, line[i]);
		map->y += 40;
		ptr = ptr->next;
	}
}

int	render(t_map *map, t_list **root)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, map->w * 40 - 1, map->h * 40 - 1 , "robin");
	put_map(map, root);
	mlx_loop(mlx);
	return (0);
}