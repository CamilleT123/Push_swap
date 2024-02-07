/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctruchot <ctruchot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:36:58 by ctruchot          #+#    #+#             */
/*   Updated: 2024/02/07 13:55:24 by ctruchot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rrr : rra et rrb en même temps

int	ft_rrr(t_list *stack_a, t_list *stack_b)
{
	if (ft_reverse_rotate_a(stack_a) != 0 || ft_reverse_rotate_b(stack_b) != 0)
		return (1);
	printf("rrr\n");
	return (0);
}
