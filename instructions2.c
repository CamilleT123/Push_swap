/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctruchot <ctruchot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:36:02 by ctruchot          #+#    #+#             */
/*   Updated: 2024/02/15 17:20:46 by ctruchot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// ra (rotate a) : Décale d’une position vers le haut 
// tous les élements de la pile a.
// Le premier élément devient le dernier.

int	ft_rotate_a(t_list *stack_a, t_list *stack_b, int call)
{
	t_element	*buff;
	t_element	*last;

	if (stack_a->size < 2)
		return (1);
	last = ft_lstlast(stack_a->first);
	buff = stack_a->first;
	stack_a->first = stack_a->first->next;
	last->next = buff;
	last->next->next = NULL;
	if (call == 0)
	{
		ft_printf("ra\n");
		update_stacks_info(stack_a, stack_b);
	}
	return (0);
}
// rb (rotate b) : Décale d’une position vers le haut 
// tous les élements de la pile b.
// Le premier élément devient le dernier.

int	ft_rotate_b(t_list *stack_a, t_list *stack_b, int call)
{
	t_element	*buff;
	t_element	*last;

	if (stack_b->size < 2)
		return (1);
	last = ft_lstlast(stack_b->first);
	buff = stack_b->first;
	stack_b->first = stack_b->first->next;
	last->next = buff;
	last->next->next = NULL;
	if (call == 0)
	{
		ft_printf("rb\n");
		update_stacks_info(stack_a, stack_b);
	}
	return (0);
}

// rr : ra et rb en même temps.

int	ft_rr(t_list *stack_a, t_list *stack_b)
{
	if (ft_rotate_a(stack_a, stack_b, 1) != 0
		|| ft_rotate_b(stack_a, stack_b, 1) != 0)
		return (1);
	ft_printf("rr\n");
	update_stacks_info(stack_a, stack_b);
	return (0);
}

// rra (reverse rotate a) : Décale d’une position vers le bas 
// tous les élements de
// la pile a. Le dernier élément devient le premier.

// je sauvegarde le premier noeud
// je place le dernier noeud en prems
// je fais pointer le nouveau prems vers l'ancien premier qui 
// est decale vers le bas

int	ft_reverse_rotate_a(t_list *stack_a, t_list *stack_b, int call)
{
	t_element	*buff;
	t_element	*last;
	t_element	*almostlast;

	update_stacks_info(stack_a, stack_b);
	if (stack_a->size < 2)
		return (1);
	last = ft_lstlast(stack_a->first);
	almostlast = ft_lstalmostlast(stack_a->first);
	buff = stack_a->first;
	stack_a->first = last;
	stack_a->first->next = buff;
	almostlast->next = NULL;
	if (call == 0)
	{
		ft_printf("rra\n");
		update_stacks_info(stack_a, stack_b);
	}
	return (0);
}

// rrb (reverse rotate b) : Décale d’une position 
// vers le bas tous les élements de
// la pile b. Le dernier élément devient le premier.

int	ft_reverse_rotate_b(t_list *stack_a, t_list *stack_b, int call)
{
	t_element	*buff;
	t_element	*last;
	t_element	*almostlast;

	if (stack_b->size < 2)
		return (1);
	last = ft_lstlast(stack_b->first);
	almostlast = ft_lstalmostlast(stack_b->first);
	buff = stack_b->first;
	stack_b->first = last;
	stack_b->first->next = buff;
	almostlast->next = NULL;
	if (call == 0)
	{
		ft_printf("rrb\n");
		update_stacks_info(stack_a, stack_b);
	}
	return (0);
}
