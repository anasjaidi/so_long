/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <ajaidi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 23:38:49 by ajaidi            #+#    #+#             */
/*   Updated: 2022/02/24 23:49:09 by ajaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	f1(t_all *all, char *line, t_list *ptr)
{
	key_13_utils(all, ptr, line);
	mlx_destroy_window(all->mlx->mlx, all->mlx->win);
	printf("you win\n");
	ft_lstclear(&all->root);
	exit(0);
}

void	f2(t_all *all, char *line, int x, int y)
{
	line[all->mlx->px - x] = 'P';
	line[all->mlx->px - y] = '0';
	mlx_destroy_window(all->mlx->mlx, all->mlx->win);
	printf("you win\n");
	ft_lstclear(&all->root);
	exit(0);
}
