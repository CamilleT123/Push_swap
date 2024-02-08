/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctruchot <ctruchot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:43:29 by ctruchot          #+#    #+#             */
/*   Updated: 2024/02/08 18:19:07 by ctruchot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

// Check if the order of the list is correct or if it should be sorted

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


// pour identifier le targetnode : parcourir a en cherchant le smallest bigger pour b

t_element *identify_target_node(t_element *element_b, t_element *element_a)
{
	t_element *target_node;
	target_node = malloc(sizeof(t_element));
	
	target_node->nb = INT_MAX;
	target_node->next = NULL;
	// printf("\nelement_b=%ld\n", element_b->nb);
	while (element_a)
	{
		// printf("element_a=%ld\n", element_a->nb);
		// printf("target=%ld\n", target_node->nb);
		if (element_b->nb < element_a->nb && target_node->nb > element_a->nb)
		{
			free(target_node);
			target_node = element_a;
		}
		// printf("element_next=%p\n", element_a->next);
		element_a = element_a->next;
	}
	// printf("targetnode=%ld\n", target_node->nb);
	return (target_node);
}

bool is_above_median(t_element *element, t_list *stack)
{
	int median;
	
	median = stack->size / 2;
	printf("median=%d\n", median);
	if (element->current_position < median)
		return (true);
	else
		return (false);
}

int identify_current_position(t_element *element_x, t_element *element)
{
	int i = 0;
	while (element != element_x)
	{
		i++;
		element = element->next;
	}
	return (i);
}

int calculate_cost_to_top(t_element *element, t_list *stack)
{
	if (element->above_median == true)
		element->cost_to_top = element->current_position;
	if (element->above_median == false)
		element->cost_to_top = stack->size - element->current_position;
	printf("cost=%d", element->cost_to_top);
	return (0);
}

int full_b_init(t_list *stack_b, t_list *stack_a)
{
	t_element *element;
	element = stack_b->first;
	// printf("element=%ld\n", element->nb);
	// printf("stack_afirst=%ld\n", stack_a->first->nb);
	while (element)
	{
		element->target_node = identify_target_node(element, stack_a->first);
		element->current_position = identify_current_position(element, stack_b->first);
		printf("element=%ld\ncurrent_pos=%d\n", element->nb, element->current_position);
		element->above_median = is_above_median(element, stack_b);
		calculate_cost_to_top(element, stack_a);
		element = element->next;
	}
	// calculate_cost();
	return (0);
}

int ft_algo(t_list *stack_a, t_list *stack_b)
{
	while (stack_a->size > 3 && check_order(stack_a->first) != 0)
	{
		ft_push_b(stack_a, stack_b);
		stack_a->size = ft_lstsize(stack_a->first);
		// printf("size=%d\n", stack_a->size);
	}
	if (check_order(stack_a->first) != 0)
		order_three_a(stack_a);
	print_list(stack_a);
	print_list(stack_b);
	full_b_init(stack_b, stack_a);
	return (0);
}

t_element *is_max(t_list *stack)
{
	t_element *element;
	element = stack->first;
	t_element *biggest;
	biggest = NULL;
	if (!element)
		return (NULL);
	if (element->nb > element->next->nb)
			biggest = element;
	else
		biggest = element->next;
	while (element->next)
	{
		element = element->next;
		if (biggest->nb < element->nb)
			biggest = element;
	}
	// printf("biggest3=%d\n", biggest->nb);
	return (biggest);
}

int order_three_a(t_list *stack)
{
	t_element *biggest;
	biggest = is_max(stack);
	if (biggest == stack->first)
		ft_rotate_a(stack);
	else if (biggest == stack->first->next)
		ft_reverse_rotate_a(stack);
	if (stack->first->nb > stack->first->next->nb)
		ft_swap_a(stack);
	return (0);
}

int check_order(t_element *element)
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


// find the min and max
//  pointeur sur le last A and B 
// bool ??
// index, above median, cheapest + poineur sur target node

// algo if 2 algo if 3 algo for more