/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctruchot <ctruchot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:34:09 by ctruchot          #+#    #+#             */
/*   Updated: 2024/02/09 14:22:40 by ctruchot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	char **strarg;
	t_list *stack_a;
	t_list *stack_b;
	int	i;
	
	stack_a = NULL;
	stack_b = NULL;
	strarg = NULL;
	i = 0;
	if (ac == 1 || (ac == 2 && av[1][0] == 0))
		return (1);
	else if (ac == 2)
	{
		strarg = ft_split(av[1], ' ');
		while (strarg[i])
			i++;
		stack_a = stack_a_init(i, strarg);
		free_tab(strarg);
	}
	else
		stack_a = stack_a_init(ac, av);
	if (stack_a != NULL)
		stack_b = stack_b_init();
	print_list(stack_a);
	print_list(stack_b);
	if (stack_a->size == 1)
		return (free_list(stack_a), free_list(stack_b), 0);
	if (check_order(stack_a->first) == 0)
		return (free_list(stack_a), free_list(stack_b), 0);
	if (stack_a->size == 2)
		ft_swap_a(stack_a);
	if (stack_a->size == 3)
		order_three_a(stack_a);
	if (stack_a->size > 3)
		ft_order_list(stack_a, stack_b);
	print_list(stack_a);
	print_list(stack_b);
	free_list(stack_a);
	free_list(stack_b);
}
		