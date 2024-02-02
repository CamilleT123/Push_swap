/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctruchot <ctruchot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:58:26 by ctruchot          #+#    #+#             */
/*   Updated: 2024/02/02 17:23:22 by ctruchot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_lstiter(t_list *lst, void (*f)(void *))
// {
// 	if (!lst || !f)
// 		return ;
// 	while (lst)
// 	{
// 		f(lst->content);
// 		lst = lst->next;
// 	}
// }

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if ((*lst) == NULL)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	temp = *lst;
	*lst = new;
	new->next = temp;
}

int	ft_lstsize(t_list *lst)
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

t_list	*ft_lstnew(int nb)
{
	t_list	*element;

	element = malloc(sizeof(t_list));
	if (element == NULL)
		return (NULL);
	element->nb = nb;
	element->next = NULL;
	return (element);
}

int main(void)
{
	int nb;

	nb = 0;
	t_list **list;
	
	list = malloc(sizeof(t_list *));
	t_list *element = ft_lstnew(nb); 
	*list = element;
	ft_lstadd_back(list, ft_lstnew(3));
	
}
// 	while (i < size)
// 	{
// 		temp = malloc;
// 		temp.data = x;
// 		temp.next = NULL;
// 		ft_add_back(list, temp);
// 		i++; 
// 	}
// 	t_list	*ptr1;
// 	t_list	*ptr2;

// 	ptr1 = malloc(sizeof(t_list));
// 	if (ptr1 == NULL)
// 		return (NULL);
// 	ptr1->content = game->player;
// 	ptr1->next = NULL;

// 	ptr2 = malloc(sizeof(t_list));
// 	if (ptr2 == NULL)
// 		return (NULL);
// 	ptr2->content = game->player2;
// 	// ptr2->next = NULL;
	
// 	ptr1->next = ptr2;
// 	ptr2->next = ptr1;
// 	if (ptr1 == NULL)
// 		printf("list is empty");
// 	game->list.ptr = ptr1;
//  	return (0);
// }