/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctruchot <ctruchot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:29:03 by ctruchot          #+#    #+#             */
/*   Updated: 2024/02/13 15:35:25 by ctruchot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_above_median(t_element *element, t_list *stack)
{
	int	median;

	if (stack->size % 2 == 0)
		median = stack->size / 2;
	else
		median = stack->size / 2 + 1;
	if (element->position < median)
		element->above_median = true;
	else
		element->above_median = false;
	return (0);
}

t_element	*identify_smallest(t_list *stack)
{
	t_element	*element;
	t_element	*smallest;

	element = stack->first;
	smallest = malloc(sizeof(t_element));
	smallest->nb = INT_MAX;
	smallest->next = NULL;
	while (element)
	{
		if (element->nb < smallest->nb)
		{
			if (smallest->nb == INT_MAX)
				free(smallest);
			smallest = element;
		}
		element = element->next;
	}
	return (smallest);
}

t_element	*identify_biggest(t_list *stack)
{
	t_element	*element;
	t_element	*biggest;

	element = stack->first;
	biggest = malloc(sizeof(t_element));
	biggest->nb = INT_MIN;
	biggest->next = NULL;
	while (element)
	{
		if (element->nb > biggest->nb)
		{
			if (biggest->nb == INT_MIN)
				free(biggest);
			biggest = element;
		}
		element = element->next;
	}
	return (biggest);
}

int	identify_position(t_element *element_x, t_element *element)
{
	int	i;

	i = 0;
	while (element != element_x)
	{
		i++;
		element = element->next;
	}
	element_x->position = i;
	return (0);
}

// int	calculate_cost_to_top(t_element *element, t_list *stack)
// {
// 	if (element->above_median == true)
// 		element->cost_to_top = element->position;
// 	if (element->above_median == false)
// 		element->cost_to_top = stack->size - element->position;
// 	return (0);
// }

// int	calculate_cost_to_target(t_element *element)
// {
// 	if (element->above_median == true
// 		&& element->target_node->above_median == true)
// 		element->cost_to_target = element->cost_to_top + 1;
// 	if (element->above_median == false
// 		&& element->target_node->above_median == false)
// 		element->cost_to_target = element->cost_to_top + 1;
// 	if ((element->above_median == true
// 			&& element->target_node->above_median == false)
// 		|| (element->above_median == false
// 			&& element->target_node->above_median == true))
// 		element->cost_to_target = element->cost_to_top
// 			+ element->target_node->cost_to_top + 1;
// 	return (0);
// }

// int	identify_target_node(t_element *element_b, t_list *stack_a)
// {
// 	t_element	*element_a;
// 	long int	target_nb;

// 	element_a = stack_a->first;
// 	target_nb = INT_MAX;
// 	while (element_a)
// 	{
// 		if (element_b)
// 		{
// 			if (element_b->nb < element_a->nb && target_nb >= element_a->nb)
// 			{
// 				target_nb = element_a->nb;
// 				element_b->target_node = element_a;
// 			}
// 		}
// 		element_a = element_a->next;
// 	}
// 	if (target_nb == INT_MAX && element_b->target_node == NULL)
// 		element_b->target_node = identify_smallest(stack_a);
// 	return (0);
// }

// t_element	*identify_cheapest(t_list *stack)
// {
// 	t_element	*element;
// 	t_element	*cheapest;
// 	int			cheapest_cost;

// 	element = stack->first;
// 	cheapest = NULL;
// 	cheapest_cost = INT_MAX;
// 	while (element)
// 	{
// 		if (element->cost_to_target < cheapest_cost)
// 		{
// 			cheapest_cost = element->cost_to_target;
// 			cheapest = element;
// 		}
// 		element = element->next;
// 	}
// 	return (cheapest);
// }
