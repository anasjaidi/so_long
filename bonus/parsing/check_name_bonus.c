/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 02:05:01 by ajaidi            #+#    #+#             */
/*   Updated: 2022/01/16 02:05:04 by ajaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	check_name(char *str)
{
	int		i;
	char	*find;
	int		j;

	i = 0;
	find = ".ber";
	j = -1;
	while (str[i])
	{
		j = -1;
		while (str[i] == find[++j])
		{
			if (!find[j + 1])
				return (1);
			i++;
		}
		i++;
	}
	printf("map name invalid\n");
	exit(0);
}
