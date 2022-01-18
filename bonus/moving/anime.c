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
	if(all->enemy->dir == 0)
	{
		if(all->enemy->x[i] == '0')
		{
			line[all->enemy->x[i]] = 'R';
			line[all->enemy->x[i - 1]] = '0';
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
}

void	move2(t_all *all, int i ,char * line)
{
	if(all->enemy->dir == 0)
	{
		if(all->enemy->x[i - 1] == '0')
		{
			line[all->enemy->x[i - 1]] = 'R';
			line[all->enemy->x[i]] = '0';
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
}

void	enemy_move(t_all *all)
{
	static int i;
	char *line;
	t_list	*p;
	int j = 0;
	p = all->root;
	all->enemy->dir = 0;
	while (1)
	{
		p = all->root;
		i = 0;
		if (!all->enemy->i)
			return ;
		if (j > all->enemy->i)
		{
				j = 0;
				break;
		}
		while (i < j)
		{
			p = p->next;
		}
		line = p->content;
		move1(all,j, line);
		j++;
	}
}

int	anime(t_all *all)
{
	enemy_move(all);
	return (0);
}

