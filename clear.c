/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctruchot <ctruchot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:00:52 by ctruchot          #+#    #+#             */
/*   Updated: 2024/02/07 15:04:44 by ctruchot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int free_list(t_list *stack) // comment utiliser lstdelone et lstclear?
{
	if (stack->first == NULL)
		return (free(stack), 1);
	while (stack->first->next != NULL)
	{
		t_element *last = ft_lstlast(stack->first); 
		// printf("last%d\n", last->nb);
		t_element *almostlast = ft_lstalmostlast(stack->first);
		// printf("almostlast%d\n", almostlast->nb);
		almostlast->next = NULL;
		// printf("freeing%d", last->nb);
		free(last);
	}
	free(stack->first);
	free(stack);
	return (0);
}

// void	ft_lstclear(t_list **lst, void (*del)(void *))
// {
// 	t_list	*tmp;

// 	if (!lst || !del || !(*lst))
// 		return ;
// 	while (*lst)
// 	{
// 		del((*lst)->content);
// 		tmp = (*lst);
// 		(*lst) = (*lst)->next;
// 		free((tmp));
// 	}
// 	*lst = NULL;
// }

// void	ft_lstdelone(t_list *lst, void (*del)(void *))
// {
// 	if (!lst || !del)
// 		return ;
// 	del(lst->content);
// 	free(lst);
// 	lst = NULL;
// }