/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctruchot <ctruchot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:55:29 by ctruchot          #+#    #+#             */
/*   Updated: 2024/02/07 13:55:56 by ctruchot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> // remplacer par ft_printf

// sa (swap a) : Intervertit les 2 premiers éléments au sommet de la pile a.
// Ne fait rien s’il n’y en a qu’un ou aucun.

// je sauvegarde le pointeur sur le premier noeud
// je fais pointer le premier pointeur vers le 2e noeud
// je fais pointer le nouveau premier noeud vers la sauvegarde
// je fais pointer la sauvegarde integree a la liste (donc en 2e) 
// vers le 3e noeud

int	ft_swap_a(t_list *stack)
{
	t_element	*buff;
	t_element	*third;

	if (stack->size < 2)
		return (1);
	buff = stack->first;
	third = stack->first->next->next;
	buff = stack->first;
	stack->first = stack->first->next;
	stack->first->next = buff;
	stack->first->next->next = third;
	printf("sa\n");
	return (0);
}

// sb (swap b ) : Intervertit les 2 premiers éléments au sommet de la pile b.
// Ne fait rien s’il n’y en a qu’un ou aucun.

int	ft_swap_b(t_list *stack)
{
	t_element	*buff;
	t_element	*third;

	if (stack->size < 2)
		return (1);
	buff = stack->first;
	third = stack->first->next->next;
	buff = stack->first;
	stack->first = stack->first->next;
	stack->first->next = buff;
	stack->first->next->next = third;
	printf("sb\n");
	return (0);
}

// // ss : sa et sb en même temps.

int	ft_ss(t_list *stack_a, t_list *stack_b)
{
	if (ft_swap_a(stack_a) != 0 || ft_swap_b(stack_b) != 0)
		return (1);
	printf("ss\n");
	return (0);
}

// // pa (push a) : Prend le premier élément au sommet de b et le met sur a.
// // Ne fait rien si b est vide.

int	ft_push_a(t_list *stack_a, t_list *stack_b)
{
	t_element	*buff_a;
	t_element	*buff_b;

	if (stack_b->size < 1)
		return (1);
	if (stack_a->first != NULL)
		buff_a = stack_a->first;
	else
		buff_a = NULL;
	buff_b = stack_b->first->next;
	stack_a->first = stack_b->first;
	stack_a->first->next = buff_a;
	stack_b->first = buff_b;
	stack_b->size -= 1;
	stack_a->size += 1;
	printf("pa\n");
	return (0);
}

// // pb (push b) : Prend le premier élément au sommet de a et le met sur b.
// // Ne fait rien si a est vide.

int	ft_push_b(t_list *stack_a, t_list *stack_b)
{
	t_element	*buff_a;
	t_element	*buff_b;

	if (stack_a->size < 1)
		return (1);
	if (stack_b->first != NULL)
		buff_b = stack_b->first;
	else
		buff_b = NULL;
	buff_a = stack_a->first->next;
	stack_b->first = stack_a->first;
	stack_b->first->next = buff_b;
	stack_a->first = buff_a;
	stack_a->size -= 1;
	stack_b->size += 1;
	printf("pb\n");
	return (0);
}
