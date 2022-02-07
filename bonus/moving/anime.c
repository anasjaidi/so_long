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

void	move2(t_all *all, int i, char *line);

long	getsec(void)
{
	struct timeval time;
	gettimeofday(&time, NULL);
	return time.tv_sec;
}

void	ft_sleep(unsigned int sec)
{

	long curr_sec = getsec();

	while (1)
	{
		if (getsec() - curr_sec >= sec)
			return ;
	}
}

void	change_dir(t_all *all)
{
	if(all->enemy->dir == 0)
		all->enemy->dir = 1;
	else
		all->enemy->dir = 0;
}

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
				change_dir(all);
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
				change_dir(all);
				move1(all,i,line);	
		}
	}
	put_map(all);
}

void	enemy_move(t_all *all)
{
	// static int i2;
	// printf("Fuck %d\n",i2);
	// i2++;
	static int pp = 0;
	int i;
	char *line = NULL;
	t_list	*p = NULL;
	all->enemy->dir = 1;
	while (1)
	{
		p = all->root;
		i = 0;
		if (!all->enemy->i)
			return ;
		if (pp >= all->enemy->i)
		{
				pp = 0;
				break;
		}
		int d;
		d = 0;
		while (++d < all->enemy->y[pp])
			p = p->next;
		line = p->content;
		move1(all, pp,line);
		put_map(all);
		pp++;
	}
}

int	anime(t_all *all)
{
	enemy_move(all);
	put_map(all);
	return (0);
}