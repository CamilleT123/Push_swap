/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctruchot <ctruchot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:43:29 by ctruchot          #+#    #+#             */
/*   Updated: 2024/02/14 17:55:45 by ctruchot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// Check if the order of the list is correct or if it should be sorted

int	check_order(t_element *element)
{
	if (!element)
		return (1);
	while (element->next)
	{
		if (element->nb > element->next->nb)
			return (-1);
		element = element->next;
	}
	return (0);
}

// function orders 3 nodes

int	order_three_a(t_list *stack_a, t_list *stack_b)
{
	t_element	*biggest;

	biggest = identify_biggest(stack_a);
	if (biggest == stack_a->first)
		ft_rotate_a(stack_a, stack_b, 0);
	else if (biggest == stack_a->first->next)
		ft_reverse_rotate_a(stack_a, stack_b, 0);
	if (stack_a->first->nb > stack_a->first->next->nb)
		ft_swap_a(stack_a, stack_b, 0);
	return (0);
}

// functions pushes nodes from a to b until there are only 3 nodes in a
// or if what remains in a is ordered
// if only 3 nodes remain in stack_a, function order_three_a orders
// the remaining nodes.
// fill the nodes info of both stacks,
// identify the cheapest node to move next to its target node and moves the node

int	ordering_first_part(t_list *stack_a, t_list *stack_b)
{
	t_element	*cheapest;

	while (stack_a->size > 3 && check_order(stack_a->first) != 0)
		ft_push_b(stack_a, stack_b);
	if (stack_a->size == 3 && check_order(stack_a->first) != 0)
		order_three_a(stack_a, stack_b);
	cheapest = identify_cheapest(stack_b);
	move_nodes(cheapest, stack_a, stack_b);
	return (0);
}

int	ordering_second_part(t_list *stack_a, t_list *stack_b)
{
	t_element	*cheapest;

	cheapest = identify_cheapest(stack_b);
	move_nodes(cheapest, stack_a, stack_b);
	return (0);
}
