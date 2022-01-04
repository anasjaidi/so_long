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

#include "get_next_line.h"

char	*read_line(char *path)
{
	char    *line;
    int     fd;
    int     error;

    fd = open(path, O_RDWR);
    while ((line = get_next_line(fd)))
    {
        if (!error)
            push_line(linked,line);
        else
            free_all(linked)

    }
}