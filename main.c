/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctruchot <ctruchot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:34:09 by ctruchot          #+#    #+#             */
/*   Updated: 2024/02/15 18:11:00 by ctruchot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1 || (ac == 2 && av[1][0] == 0))
		return (1);
	else if (ac == 2)
		stack_a = parsing_string(av, stack_a);
	else
		stack_a = stack_a_init(ac, av, 0);
	stack_b = stack_b_init(stack_a);
	if (stack_a->size == 1)
		return (free_list(stack_a), free_list(stack_b), 0);
	if (check_order(stack_a->first) == 0)
		return (free_list(stack_a), free_list(stack_b), 0);
	if (stack_a->size == 2)
		ft_swap_a(stack_a, stack_b, 0);
	if (stack_a->size == 3)
		order_three_a(stack_a, stack_b);
	if (stack_a->size > 3)
		ordering_first_part(stack_a, stack_b);
	free_list(stack_a);
	free_list(stack_b);
	return (0);
}
