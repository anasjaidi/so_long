/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 21:57:53 by ajaidi            #+#    #+#             */
/*   Updated: 2022/01/05 21:57:57 by ajaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	p = *lst;
	while (p->next)
		p = p->next;
	p->next = new;
	p->next->prev = p;
}

void	ft_lstclear(t_list **lst)
{
	t_list	*p;
	t_list	*q;

	p = *lst;
	if (!p)
		return ;
	while (p)
	{
		q = p;
		p = p->next;
		free(q->content);
		free(q);
	}
	*lst = NULL;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->prev = NULL;
	new->content = content;
	new->next = NULL;
	return (new);
}
