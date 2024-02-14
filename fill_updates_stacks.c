/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_updates_stacks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctruchot <ctruchot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:49:40 by ctruchot          #+#    #+#             */
/*   Updated: 2024/02/14 17:39:43 by ctruchot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_a_fill_info(t_list *stack_a)
{
	t_element	*element;

	element = stack_a->first;
	while (element)
	{
		identify_position(element, stack_a->first);
		is_above_median(element, stack_a);
		calculate_cost_top(element, stack_a);
		element = element->next;
	}
	return (0);
}

int	stack_b_fill_info(t_list *stack_b, t_list *stack_a)
{
	t_element	*element;

	element = stack_b->first;
	while (element)
	{
		identify_target_node(element, stack_a);
		identify_position(element, stack_b->first);
		is_above_median(element, stack_b);
		calculate_cost_top(element, stack_b);
		calculate_cost_target(element);
		element = element->next;
	}
	return (0);
}

int	update_stacks_info(t_list *stack_a, t_list *stack_b)
{
	stack_a_fill_info(stack_a);
	stack_b_fill_info(stack_b, stack_a);
	return (0);
}
