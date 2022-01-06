/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:32:36 by ajaidi            #+#    #+#             */
/*   Updated: 2022/01/04 13:32:38 by ajaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# define BUFFER_SIZE 100000
# define EMPTY_FILE "Error the map is empty" 
# define NOT_RECTANGULAR "Error the map is not rectangular" 
# define NOT_ONE "Error the map is not surrounded by wall" 
# define MORE_COMP "ther is more tha 01ECP in map"
# define MISSING "something missing in map"

typedef struct s_list {
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_map
{
    int w;
    int c;
    int e;
    int p;
    int h;
} t_map;
int	    check_one(char *line1, char *line2);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstclear(t_list **lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
char	*read_line(char *path, t_map *map);
int     check_wall(char *line, t_map *map);
int	    check_child(char c, t_map *map);
int	    check_comp(char *line, t_map *map);
int	    check_char(char *line, t_map *map);
int	    check_line(char *line, t_map *map, t_list **root);
int 	print_error(int n);
char	*ft_strdup(const char *s1);
int		ft_strchr(char *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);

#endif
