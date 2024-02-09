/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctruchot <ctruchot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:29:03 by ctruchot          #+#    #+#             */
/*   Updated: 2024/02/09 14:48:50 by ctruchot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_above_median(t_element *element, t_list *stack)
{
	int	median;

	median = stack->size / 2; // ok en cas de nombre impair ?
	if (element->current_position < median)
		return (true);
	else
		return (false);
}

t_element	*identify_target_node(t_element *element_b, t_element *element_a)
{
	t_element	*target_node;

	target_node = malloc(sizeof(t_element));
	target_node->nb = INT_MAX;
	target_node->next = NULL;
	// printf("\nelement_b=%ld\n", element_b->nb);
	while (element_a)
	{
		// printf("element_a=%ld\n", element_a->nb);
		// printf("target=%ld\n", target_node->nb);
		if (element_b)
		{
			if (element_b->nb < element_a->nb
				&& target_node->nb > element_a->nb)
			{
				free(target_node);
				target_node = element_a;
			}
		}
		// printf("element_next=%p\n", element_a->next);
		element_a = element_a->next;
	}
	printf("targetnode=%ld\n", target_node->nb);
	return (target_node);
}

int	identify_current_position(t_element *element_x, t_element *element)
{
	int	i;

	i = 0;
	while (element != element_x)
	{
		i++;
		element = element->next;
	}
	return (i);
}

int	calculate_cost_to_top(t_element *element, t_list *stack)
{
	if (element->above_median == true)
		element->cost_to_top = element->current_position;
	if (element->above_median == false)
		element->cost_to_top = stack->size - element->current_position;
	printf("cost=%d\n", element->cost_to_top);
	return (0);
}

int	calculate_cost_to_target(t_element *element)
{
	printf("\nelement=%ld\n", element->nb);
	printf("targetnode=%ld\n", element->target_node->nb);
	printf("abovemed=%d\n", element->target_node->above_median);
	printf("costtotopdetarget=%d\n", element->target_node->cost_to_top);

	if (element->above_median == true && element->target_node->above_median == true)
		element->cost_to_target = element->cost_to_top + 1;
	if (element->above_median == false && element->target_node->above_median == false)
		element->cost_to_target = element->cost_to_top + 1;
	if ((element->above_median == true && element->target_node->above_median == false) 
		|| (element->above_median == false && element->target_node->above_median == true))
		element->cost_to_target = element->cost_to_top + element->target_node->cost_to_top + 1;
	// printf("cost=%d\n", element->cost_to_target);
	return (0);
}



