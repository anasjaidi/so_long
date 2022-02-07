/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anime.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:07:00 by ajaidi            #+#    #+#             */
/*   Updated: 2022/01/18 15:07:06 by ajaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

#include <sys/time.h>

void	move1(t_all *all, int i, char *line)
{
	if(all->enemy->dir == 1)
	{
		if(line[all->enemy->x[i]] == '0')
		{
			line[all->enemy->x[i]] = 'R';
			line[all->enemy->x[i] - 1] = '0';
			all->enemy->x[i]++;
		}
		else if(all->enemy->x[i] == 'P')
		{
			exit(0);
		}
		else
		{
				all->enemy->dir = 0;
				move2(all,i, line);	
		}
	}
	put_map(all);
}

void	move2(t_all *all, int i ,char * line)
{
	if(all->enemy->dir == 0)
	{
		if(line[all->enemy->x[i] - 2] == '0')
		{
			line[all->enemy->x[i] - 2] = 'R';
			line[all->enemy->x[i]- 1] = '0';
			all->enemy->x[i]--;
		}
		else if(all->enemy->x[i - 1] == 'P')
		{
			exit(0);
		}
		else
		{
				all->enemy->dir = 1;
				move1(all,i,line);	
		}
	}
	put_map(all);
}

void	enemy_move(t_all *all)
{
	int pp ;
	pp = 0;
	char *line = NULL;
	t_list	*p = NULL;
	all->enemy->dir = 1;
	if (!all->enemy->i)
			return ;
	while (pp < all->enemy->i)
	{
		p = all->root;
		int d;
		d = 0;
		while (++d < all->enemy->y[pp])
			p = p->next;
		line = p->content;
		move1(all, pp,line);
		pp++;
	}
}

int	anime(t_all *all)
{
	enemy_move(all);
	
	return (0);
}