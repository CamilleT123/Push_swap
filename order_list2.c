/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_list2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctruchot <ctruchot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:52:29 by ctruchot          #+#    #+#             */
/*   Updated: 2024/02/15 11:19:33 by ctruchot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_together(t_element *cheapest, t_list *stack_a, t_list *stack_b)
{
	if (cheapest->cost_top
		+ cheapest->target_node->cost_top > cheapest->cost_target)
	{
		if ((cheapest->cost_top < cheapest->target_node->cost_top
				&& cheapest->above_median == false)
			|| (cheapest->cost_top > cheapest->target_node->cost_top
				&& cheapest->target_node->above_median == false))
			ft_rrr(stack_a, stack_b);
		else if ((cheapest->cost_top <= cheapest->target_node->cost_top
				&& cheapest->above_median == true)
			|| (cheapest->cost_top >= cheapest->target_node->cost_top
				&& cheapest->target_node->above_median == true))
			ft_rr(stack_a, stack_b);
	}
	else
		finish_move(cheapest, stack_a, stack_b);
	return (0);
}

int	finish_move(t_element *cheapest, t_list *stack_a, t_list *stack_b)
{
	while (cheapest->position > 0)
	{
		if (cheapest->above_median == true)
			ft_rotate_b(stack_a, stack_b, 0);
		else
			ft_reverse_rotate_b(stack_a, stack_b, 0);
	}
	while (cheapest->target_node->position > 0)
	{
		if (cheapest->target_node->above_median == true)
			ft_rotate_a(stack_a, stack_b, 0);
		else
			ft_reverse_rotate_a(stack_a, stack_b, 0);
	}
	return (0);
}

int	place_bigger_down(t_list *stack_a, t_list *stack_b)
{
	if (stack_a->biggest->above_median == true)
		ft_rotate_a(stack_a, stack_b, 0);
	else if (stack_a->biggest->above_median == false)
		ft_reverse_rotate_a(stack_a, stack_b, 0);
	return (0);
}

// on bouge le cheapest
// si en 2e position voir si swap n'est pas mieux que rotate ?

int	move_nodes(t_element *cheapest, t_list *stack_a, t_list *stack_b)
{
	while (cheapest->position > 0 && cheapest->target_node->position > 0)
	{
		if (cheapest->above_median == true
			&& cheapest->target_node->above_median == true)
			ft_rr(stack_a, stack_b);
		if (cheapest->above_median == false
			&& cheapest->target_node->above_median == false)
			ft_rrr(stack_a, stack_b);
		if ((cheapest->above_median == true
				&& cheapest->target_node->above_median == false)
			|| (cheapest->above_median == false
				&& cheapest->target_node->above_median == true))
			move_together(cheapest, stack_a, stack_b);
	}
	finish_move(cheapest, stack_a, stack_b);
	if (cheapest->position == 0 && cheapest->target_node->position == 0)
		ft_push_a(stack_a, stack_b);
	if (stack_b->first != NULL)
		ordering_second_part(stack_a, stack_b);
	while (stack_a->biggest->position != stack_a->size - 1)
		place_bigger_down(stack_a, stack_b);
	return (0);
}
