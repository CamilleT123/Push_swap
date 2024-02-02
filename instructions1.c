/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctruchot <ctruchot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:55:29 by ctruchot          #+#    #+#             */
/*   Updated: 2024/02/02 19:07:38 by ctruchot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap_list.h"


// sa (swap a) : Intervertit les 2 premiers éléments au sommet de la pile a.
// Ne fait rien s’il n’y en a qu’un ou aucun.

void ft_swap_a(t_stack *stack)
{
	int buff;
	
	if (stack->sizea < 2)
		return;
	buff = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = buff;
}
// sb (swap b ) : Intervertit les 2 premiers éléments au sommet de la pile b.
// Ne fait rien s’il n’y en a qu’un ou aucun.

void ft_swap_b(t_stack *stack)
{
	int buff;
	
	if (stack->sizeb < 2)
		return;
	buff = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = buff;
}
// ss : sa et sb en même temps.

void ft_ss(t_stack *stack)
{
	ft_swap_a(stack);
	ft_swap_b(stack);
}
// pa (push a) : Prend le premier élément au sommet de b et le met sur a.
// Ne fait rien si b est vide.
// pb (push b) : Prend le premier élément au sommet de a et le met sur b.
// Ne fait rien si a est vide.

// ra (rotate a) : Décale d’une position vers le haut tous les élements de la pile a.
// Le premier élément devient le dernier.


void ft_rotate_a(t_stack *stack)
{
	int i;
	int buff;
	// if (stacka[0] = NULL || stacka[1] == NULL)
	// 	return (0);
	i = 0;
	buff = stack->a[0];
	printf("buff= %d\n", buff);
	printf("size=%d\n", stack->sizea);
	while (i < stack->sizea - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[i] = buff;
}
// rb (rotate b) : Décale d’une position vers le haut tous les élements de la pile b.
// Le premier élément devient le dernier.


void ft_rotate_b(t_stack *stack)
{
	int i;
	int buff;
	// if (stacka[0] = NULL || stacka[1] == NULL)
	// 	return (0);
	i = 0;
	buff = stack->b[0];
	// printf("buff= %d\n", buff);
	// printf("size=%d\n", stack->sizea);
	while (i < stack->sizeb - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[i] = buff;
}
// rr : ra et rb en même temps.

void ft_rr(t_stack *stack)
{
	ft_rotate_a(stack);
	ft_rotate_b(stack);
}

// rra (reverse rotate a) : Décale d’une position vers le bas tous les élements de
// la pile a. Le dernier élément devient le premier.

void ft_reverse_rotate_a(t_stack *stack)
{
	int i;
	int buff;
	// if (stacka[0] = NULL || stacka[1] == NULL)
	// 	return (0);
	i = stack->sizea - 1;
	buff = stack->a[i];
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = buff;
}


// rrb (reverse rotate b) : Décale d’une position vers le bas tous les élements de
// la pile b. Le dernier élément devient le premier.

void ft_reverse_rotate_b(t_stack *stack)
{
	int i;
	int buff;
	// if (stacka[0] = NULL || stacka[1] == NULL)
	// 	return (0);
	i = stack->sizeb - 1;
	buff = stack->b[i];
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = buff;
}
// rrr : rra et rrb en même temps.

void ft_rrr(t_stack *stack)
{
	ft_reverse_rotate_a(stack);
	ft_reverse_rotate_b(stack);
}
