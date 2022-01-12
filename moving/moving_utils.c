/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:16:39 by ajaidi            #+#    #+#             */
/*   Updated: 2022/01/12 19:16:40 by ajaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	key_13_utils(t_all *all, t_list *ptr, char *line)
{
	line[all->mlx->px - 1] = 'P';
	line = ptr->content;
	line[all->mlx->px - 1] = '0';
}

void	check_y(t_all *all, int key)
{
	char	*line;
	int		i;
	t_list	*ptr;

	i = -1;
	ptr = all->root;
	while (ptr && ++i < all->mlx->py - 1)
		ptr = ptr->next;
	if (key == 13)
		key_13(all, ptr);
	if (key == 1)
		key_1(all, ptr);
}

int	key_hook(int key, t_all *all)
{
	if (key == 0)
		check_x(all, key);
	if (key == 1)
		check_y(all, key);
	if (key == 2)
		check_x(all, key);
	if (key == 13)
		check_y(all, key);
	if (key == 53)
	{
		ft_lstclear(&all->root);
		mlx_destroy_window(all->mlx->mlx, all->mlx->win);
		exit(0);
	}
	return (0);
}
