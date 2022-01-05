/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:56:18 by ajaidi            #+#    #+#             */
/*   Updated: 2022/01/03 13:56:23 by ajaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*read_line(char *path, t_map *map)
{
	char	*line;
	t_list	*p;
	t_list *root = NULL;
	int		fd;
	int		error;

	fd = open(path, O_RDWR);
	line = get_next_line(fd);
	if (!line)
		print_error(1);
	while (line)
	{
		error = check_line(line, map, &root);
		if (error)
			exit(0);
		line = get_next_line(fd);
	}
	p = root;
	while (p)
	{
		printf("%s",p->content);
		p = p->next;
	}
	return (NULL);
}