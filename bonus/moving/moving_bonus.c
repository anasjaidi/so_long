/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 07:25:06 by ajaidi            #+#    #+#             */
/*   Updated: 2022/01/07 07:25:06 by ajaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	key_0(t_all *all, char *line)
{
	if (line[all->mlx->px - 2] == '0')
	{
		line[all->mlx->px - 2] = 'P';
		line[all->mlx->px - 1] = '0';
		put_map(all);
		printf("instruct %d\n", all->map->in++);
	}
	else if (line[all->mlx->px - 2] == 'C')
	{
		line[all->mlx->px - 2] = 'P';
		line[all->mlx->px - 1] = '0';
		all->map->c -= 1;
		put_map(all);
		printf("instruct %d\n", all->map->in++);
	}
	else if (line[all->mlx->px - 2] == 'E' && !all->map->c)
	{
		line[all->mlx->px - 2] = 'P';
		line[all->mlx->px - 1] = '0';
		mlx_destroy_window(all->mlx->mlx, all->mlx->win);
		printf("you win\n");
		ft_lstclear(&all->root);
		exit(0);
	}
	else
		check_enemy(line[all->mlx->px - 2], all);
}

void	key_2(t_all *all, char *line)
{
	if (line[all->mlx->px] == '0')
	{
		line[all->mlx->px] = 'P';
		line[all->mlx->px - 1] = '0';
		put_map(all);
		printf("instruct %d\n", all->map->in++);
	}
	else if (line[all->mlx->px] == 'C')
	{
		line[all->mlx->px] = 'P';
		line[all->mlx->px - 1] = '0';
		all->map->c -= 1;
		put_map(all);
		printf("instruct %d\n", all->map->in++);
	}
	else if (line[all->mlx->px] == 'E' && !all->map->c)
	{
		line[all->mlx->px] = 'P';
		line[all->mlx->px - 1] = '0';
		mlx_destroy_window(all->mlx->mlx, all->mlx->win);
		printf("you win\n");
		ft_lstclear(&all->root);
		exit(0);
	}
	else
		check_enemy(line[all->mlx->px], all);
}

void	check_x(t_all *all, int key)
{
	char	*line;
	t_list	*ptr;
	int		i;

	i = -1;
	ptr = all->root;
	while (ptr && (++i < all->mlx->py - 1))
		ptr = ptr->next;
	line = ptr->content;
	if (key == 0)
		key_0(all, line);
	if (key == 2)
		key_2(all, line);
}

void	key_13(t_all *all, t_list *ptr)
{
	char	*line;

	line = ptr->prev->content;
	if (line[all->mlx->px - 1] == '0')
	{
		key_13_utils(all, ptr, line);
		put_map(all);
		printf("instruct %d\n", all->map->in++);
	}
	else if (line[all->mlx->px - 1] == 'C')
	{
		key_13_utils(all, ptr, line);
		all->map->c -= 1;
		put_map(all);
		printf("instruct %d\n", all->map->in++);
	}
	else if (line[all->mlx->px - 1] == 'E' && !all->map->c)
	{
		key_13_utils(all, ptr, line);
		mlx_destroy_window(all->mlx->mlx, all->mlx->win);
		printf("you win\n");
		ft_lstclear(&all->root);
		exit(0);
	}
	else
		check_enemy(line[all->mlx->px - 1], all);
}

void	key_1(t_all *all, t_list *ptr)
{
	char	*line;

	line = ptr->next->content;
	if (line[all->mlx->px - 1] == '0')
	{
		key_13_utils(all, ptr, line);
		put_map(all);
		printf("instruct %d\n", all->map->in++);
	}
	else if (line[all->mlx->px - 1] == 'C')
	{
		key_13_utils(all, ptr, line);
		all->map->c -= 1;
		put_map(all);
		printf("instruct %d\n", all->map->in++);
	}
	else if (line[all->mlx->px - 1] == 'E' && !all->map->c)
	{
		key_13_utils(all, ptr, line);
		mlx_destroy_window(all->mlx->mlx, all->mlx->win);
		printf("you win\n");
		ft_lstclear(&all->root);
		exit(0);
	}
	else
		check_enemy(line[all->mlx->px - 1], all);
}
