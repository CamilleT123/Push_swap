/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctruchot <ctruchot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:36:58 by ctruchot          #+#    #+#             */
/*   Updated: 2024/02/13 14:36:25 by ctruchot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rrr : rra et rrb en même temps

int	ft_rrr(t_list *stack_a, t_list *stack_b)
{
	if (ft_reverse_rotate_a(stack_a, stack_b, 1) != 0
		|| ft_reverse_rotate_b(stack_a, stack_b, 1) != 0)
		return (1);
	ft_printf("rrr\n");
	update_stacks_info(stack_a, stack_b);
	return (0);
}
