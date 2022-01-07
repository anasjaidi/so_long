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
    while(ptr && ++i < all->mlx->py)
        ptr = ptr->next;
    if (key == 0)
    {
        printf("%d",all->mlx->py);
    }
}

int key_hook(int key, t_all *all)
{
    if (key == 0)
        check_x(all, key);
    // if (key == 1)
    //     check_y(all, key);
    // if (key == 2)
    //     check_x(all, key);
    // if (key == 13)
    //     check_y(all, key);
    return (0);
}

int move(t_all *all)
{
    int key;
    key = mlx_key_hook(all->mlx->win , key_hook, all);
}