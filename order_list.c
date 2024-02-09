/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctruchot <ctruchot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:43:29 by ctruchot          #+#    #+#             */
/*   Updated: 2024/02/09 14:47:07 by ctruchot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// on bouge le cheapest

// int move_nodes(t_element *element, t_list *stack_b, t_list *stack_a)
// {
// 	t_element *element;
// 	element = stack_b->first;

// 	while (element->above_median == true
		// && element->target_node->above_median == true)
// 		ft_rr(stack_a, stack_b);
// 	while (element->above_median == false
		// && element->target_node->above_median == false)
// 		ft_rrr(stack_a, stack_b);

// 	if (element->above_median == false)
// 		element->cost_to_top = stack_b->size - element->current_position;
// 	printf("cost=%d\n", element->cost_to_top);
// 	return (0);
// }

int	stack_a_fill_info(t_list *stack_a)
{
	t_element	*element;

	element = stack_a->first;
	// printf("stack_afirst=%ld\n", stack_a->first->nb);
	while (element)
	{
		printf("\nelement=%ld\n", element->nb);
		element->current_position = identify_current_position(element,
				stack_a->first);
		printf("element=%ld\ncurrent_pos=%d\n", element->nb,
			element->current_position);
		element->above_median = is_above_median(element, stack_a);
		printf("median%d\n", element->above_median);
		calculate_cost_to_top(element, stack_a);
		printf("costtotop%d\n", element->cost_to_top);
		// calculate_cost_to_target(element, stack_b, stack_a);
		element = element->next;
	}
	return (0);
}

int	stack_b_fill_info(t_list *stack_b, t_list *stack_a)
{
	t_element	*element;

	element = stack_b->first;
	printf("element=%ld\n", element->nb);
	// printf("stack_afirst=%ld\n", stack_a->first->nb);
	while (element)
	{
		element->target_node = identify_target_node(element, stack_a->first);
		element->current_position = identify_current_position(element,
				stack_b->first);
		// printf("element=%ld\ncurrent_pos=%d\n", element->nb,
			// element->current_position);
		element->above_median = is_above_median(element, stack_b);
		calculate_cost_to_top(element, stack_b);
		calculate_cost_to_target(element);
		printf("costtotarget=%d\n", element->cost_to_target);
		element = element->next;
	}
	return (0);
}

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

int	order_three_a(t_list *stack)
{
	t_element	*biggest;

	biggest = identify_biggest(stack);
	if (biggest == stack->first)
		ft_rotate_a(stack);
	else if (biggest == stack->first->next)
		ft_reverse_rotate_a(stack);
	if (stack->first->nb > stack->first->next->nb)
		ft_swap_a(stack);
	return (0);
}

// functions pushes nodes from a to b until there are only 3 nodes in a
// or if what remains in a is ordered
// if only 3 nodes remain in stack_a, function order_three_a orders
// the remaining nodes.
// fill the nodes info of both stacks

int	ft_order_list(t_list *stack_a, t_list *stack_b)
{
	while (stack_a->size > 3 && check_order(stack_a->first) != 0)
		ft_push_b(stack_a, stack_b);
	if (stack_a->size == 3 && check_order(stack_a->first) != 0)
		order_three_a(stack_a);
	print_list(stack_a);
	print_list(stack_b);
	stack_a_fill_info(stack_a);
	stack_b_fill_info(stack_b, stack_a);
	return (0);
}

// find the min and max
// pointeur sur le last A and B
// index, cheapest

// int ft_is_min(t_list *stack)
// {
// 	t_element *element;
// 	element = stack->first;

// 	long int min = LONG_MAX;
// 	printf("min=%ld\n", min);
// 	if (!element)
// 		return (1);
// 	if (element->nb < element->next->nb)
// 			min = element->nb;
// 	while (element)
// 	{
// 		if (min > element->nb)
// 			min = element->nb;
// 		printf("min=%ld\n", min);
// 		element = element->next;
// 	}
// 	return (min);
// }
