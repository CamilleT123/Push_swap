/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctruchot <ctruchot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:52:29 by ctruchot          #+#    #+#             */
/*   Updated: 2024/02/15 17:47:03 by ctruchot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// moves stacks a and b together even though one of them is 
// above and the other is below median. 

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

// finishes to move the cheapest and target nodes to top once common
// move is no longer possible

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

// at the end, aims at placing the biggest node down

int	place_bigger_down(t_list *stack_a, t_list *stack_b)
{
	if (stack_a->biggest->above_median == true)
		ft_rotate_a(stack_a, stack_b, 0);
	else if (stack_a->biggest->above_median == false)
		ft_reverse_rotate_a(stack_a, stack_b, 0);
	return (0);
}

// the cheapest is moved until it is on top and its target is on top
// first loop aims at moving stacks a and b together until either the
// target or the cheapest is on top.
// Once one is on top, the other one continues its movement until it reaches
// the top. 
// the cheapest node is then pushed to stack a.
// until stack b is empty, the function will call the ordering_second_part
// function.
// Once b is empty, then stack a is rotated until the biggest node is below

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
