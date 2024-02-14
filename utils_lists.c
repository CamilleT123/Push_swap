/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctruchot <ctruchot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:44:07 by ctruchot          #+#    #+#             */
/*   Updated: 2024/02/13 15:56:12 by ctruchot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_element	*ft_lstnew(int nb)
{
	t_element	*element;

	element = malloc(sizeof(t_element));
	if (element == NULL)
		return (NULL);
	element->nb = nb;
	init_nodes_to_zero(element);
	element->next = NULL;
	return (element);
}

t_element	*ft_lstlast(t_element *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_lstadd_back(t_element **lst, t_element *new)
{
	if (new == NULL)
		return (1);
	if ((*lst) == NULL)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
	return (0);
}

t_element	*ft_lstalmostlast(t_element *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

int	ft_lstsize(t_element *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
