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

#include "../so_long.h"

void    check_x(t_all *all, int key)
{
    char    *line;
    t_list  *ptr;
    int i = -1;

    ptr = all->root;
    while(ptr && ++i < all->mlx->py - 1)
        ptr = ptr->next;
    line = ptr->content;
    if (key == 0)
    {
        if (line[all->mlx->px - 2] == '0')
        {
            line[all->mlx->px - 2] = 'P';
            line[all->mlx->px - 1] = '0';
            put_map(all);
        }
        if (line[all->mlx->px - 2] == 'C')
        {
            line[all->mlx->px - 2] = 'P';
            line[all->mlx->px - 1] = '0';
            all->map->c -= 1;
            put_map(all);
        }
        if (line[all->mlx->px - 2] == 'E' && !all->map->c)
        {
            printf("%d\n",all->map->c);
            line[all->mlx->px - 2] = 'P';
            line[all->mlx->px - 1] = '0';
            mlx_destroy_window(all->mlx->mlx, all->mlx->win);
            exit(0);
        }
    }
    if (key == 2)
    {
        if (line[all->mlx->px] == '0')
        {
            line[all->mlx->px] = 'P';
            line[all->mlx->px - 1] = '0';
            //all->mlx->px -= 1;
            put_map(all);
        }
        if (line[all->mlx->px] == 'C')
        {
            line[all->mlx->px] = 'P';
            line[all->mlx->px - 1] = '0';
            all->map->c -= 1;
            put_map(all);
        }
        if (line[all->mlx->px] == 'E' && !all->map->c)
        {
            line[all->mlx->px] = 'P';
            line[all->mlx->px - 1] = '0';
            mlx_destroy_window(all->mlx->mlx, all->mlx->win);
            exit(0);
        }
    }
}
void    check_y(t_all *all, int key)
{
    char    *line;
    t_list  *ptr;
    int i = -1;

    ptr = all->root;
    while(ptr && ++i < all->mlx->py - 1)
        ptr = ptr->next;
    if (key == 13)
    {
        line = ptr->prev->content;
        if (line[all->mlx->px -1 ] == '0')
        {
            line[all->mlx->px - 1] = 'P';
            line = ptr->content;
            line[all->mlx->px - 1] = '0';
            //all->mlx->px -= 1;
            put_map(all);
        }
        if (line[all->mlx->px - 1 ] == 'C')
        {
            line[all->mlx->px - 1] = 'P';
            line = ptr->content;
            line[all->mlx->px - 1] = '0';
            all->map->c -= 1;
            put_map(all);
        }
        if (line[all->mlx->px - 1] == 'E' && !all->map->c)
        {
            line[all->mlx->px - 1] = 'P';
            line = ptr->content;
            line[all->mlx->px - 1] = '0';
            mlx_destroy_window(all->mlx->mlx, all->mlx->win);
            exit(0);
        }
    }
    if (key == 1)
    {
        line = ptr->next->content;
        if (line[all->mlx->px - 1] == '0')
        {
            line[all->mlx->px - 1] = 'P';
            line = ptr->content;
            line[all->mlx->px - 1] = '0';
            //all->mlx->px -= 1;
            put_map(all);
        }
        if (line[all->mlx->px - 1] == 'C')
        {
            line[all->mlx->px - 1] = 'P';
            line = ptr->content;
            line[all->mlx->px - 1] = '0';
            all->map->c -= 1;
            put_map(all);
        }
        if (line[all->mlx->px - 1] == 'E' && !all->map->c)
        {
            line[all->mlx->px - 1] = 'P';
            line = ptr->content;
            line[all->mlx->px - 1] = '0';
            mlx_destroy_window(all->mlx->mlx, all->mlx->win);
            exit(0);
        }
    }
}

int key_hook(int key, t_all *all)
{
    if (key == 0)
        check_x(all, key);
    if (key == 1)
        check_y(all, key);
    if (key == 2)
        check_x(all, key);
    if (key == 13)
        check_y(all, key);
    return (0);
}
