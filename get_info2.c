/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctruchot <ctruchot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:29:03 by ctruchot          #+#    #+#             */
/*   Updated: 2024/02/14 17:55:56 by ctruchot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_cost_top(t_element *element, t_list *stack)
{
	if (element->above_median == true)
		element->cost_top = element->position;
	if (element->above_median == false)
		element->cost_top = stack->size - element->position;
	return (0);
}

int	calculate_cost_target(t_element *element)
{
	int	abs;

	abs = element->position - element->target_node->position;
	if (abs < 0)
		abs = abs * -1;
	if (element->above_median == true
		&& element->target_node->above_median == true)
		element->cost_target = element->cost_top + abs;
	if (element->above_median == false
		&& element->target_node->above_median == false)
		element->cost_target = element->cost_top + abs;
	if ((element->above_median == true
			&& element->target_node->above_median == false)
		|| (element->above_median == false
			&& element->target_node->above_median == true))
	{
		element->cost_target = element->cost_top
			+ element->target_node->cost_top;
		if (element->cost_top < element->target_node->cost_top
			&& element->above_median == false)
			return (0);
		if (element->cost_target > element->cost_top + abs)
			element->cost_target = element->cost_top + abs;
	}
	return (0);
}

int	identify_target_node(t_element *element_b, t_list *stack_a)
{
	t_element	*element_a;
	long long	target_nb;

	element_a = stack_a->first;
	target_nb = 2147483648;
	while (element_a)
	{
		if (element_b)
		{
			if (element_b->nb < element_a->nb && target_nb >= element_a->nb)
			{
				target_nb = element_a->nb;
				element_b->target_node = element_a;
			}
		}
		element_a = element_a->next;
	}
	if (target_nb == 2147483648)
		element_b->target_node = identify_smallest(stack_a);
	return (0);
}

t_element	*identify_cheapest(t_list *stack)
{
	t_element	*element;
	t_element	*cheapest;
	int			cheapest_cost;

	element = stack->first;
	cheapest = NULL;
	cheapest_cost = INT_MAX;
	while (element)
	{
		if (element->cost_target < cheapest_cost)
		{
			cheapest_cost = element->cost_target;
			cheapest = element;
		}
		element = element->next;
	}
	return (cheapest);
}
