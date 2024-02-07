/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctruchot <ctruchot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:36:02 by ctruchot          #+#    #+#             */
/*   Updated: 2024/02/07 13:55:40 by ctruchot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ra (rotate a) : Décale d’une position vers le haut 
// tous les élements de la pile a.
// // Le premier élément devient le dernier.

int	ft_rotate_a(t_list *stack)
{
	t_element	*buff;
	t_element	*last;

	if (stack->size < 2)
		return (1);
	last = ft_lstlast(stack->first);
	buff = stack->first;
	stack->first = stack->first->next;
	last->next = buff;
	last->next->next = NULL;
	printf("ra\n");
	return (0);
}
// rb (rotate b) : Décale d’une position vers le haut 
// tous les élements de la pile b.
// Le premier élément devient le dernier.

int	ft_rotate_b(t_list *stack)
{
	t_element	*buff;
	t_element	*last;

	if (stack->size < 2)
		return (1);
	last = ft_lstlast(stack->first);
	buff = stack->first;
	stack->first = stack->first->next;
	last->next = buff;
	last->next->next = NULL;
	printf("rb\n");
	return (0);
}

// // rr : ra et rb en même temps.

int	ft_rr(t_list *stack_a, t_list *stack_b)
{
	if (ft_rotate_a(stack_a) != 0 || ft_rotate_b(stack_b) != 0)
		return (1);
	printf("rr\n");
	return (0);
}

// rra (reverse rotate a) : Décale d’une position vers le bas 
// tous les élements de
// // la pile a. Le dernier élément devient le premier.

// je sauvegarde le premier noeud
// je place le dernier noeud en prems
// je fais pointer le nouveau prems vers l'ancien premier qui 
// est decale vers le bas
int	ft_reverse_rotate_a(t_list *stack)
{
	t_element	*buff;
	t_element	*last;
	t_element	*almostlast;

	if (stack->size < 2)
		return (1);
	last = ft_lstlast(stack->first);
	almostlast = ft_lstalmostlast(stack->first);
	buff = stack->first;
	stack->first = last;
	stack->first->next = buff;
	almostlast->next = NULL;
	printf("rra\n");
	return (0);
}
// rrb (reverse rotate b) : Décale d’une position 
// vers le bas tous les élements de
// // la pile b. Le dernier élément devient le premier.

int	ft_reverse_rotate_b(t_list *stack)
{
	t_element	*buff;
	t_element	*last;
	t_element	*almostlast;

	if (stack->size < 2)
		return (1);
	last = ft_lstlast(stack->first);
	almostlast = ft_lstalmostlast(stack->first);
	buff = stack->first;
	stack->first = last;
	stack->first->next = buff;
	almostlast->next = NULL;
	printf("rrb\n");
	return (0);
}
