/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctruchot <ctruchot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:34:09 by ctruchot          #+#    #+#             */
/*   Updated: 2024/02/07 18:04:27 by ctruchot         ###   ########.fr       */
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
	// printf("size%d\n", stack_a->size);
	if (stack_a->size == 1)
		return (free_list(stack_a), free_list(stack_b), 0);
	if (check_order(stack_a->first) == 0)
		return (free_list(stack_a), free_list(stack_b), 0);
	// ft_putstr_fd("size\n",2);
	if (stack_a->size == 2)
		ft_swap_a(stack_a);
	if (stack_a->size == 3)
		order_three_a(stack_a);
	// if (stack_a->size > 3)
		// algo
	print_list(stack_a);
	print_list(stack_b);
	free_list(stack_a);
	free_list(stack_b);
}
		// // if (stack_b->first != NULL)
		// // 	printf("firstb=%d\n", stack_b->first->nb);
		// // else
		// // 	printf("firstb=NULL\n");
		// print_list(stack_a);
		// print_list(stack_b);
		// int size = ft_lstsize(stack_a->first);
		// printf("size=%d\n", size);
		// ft_push_b(stack_a, stack_b);
		// print_list(stack_a);
		// print_list(stack_b);
		// // printf("sizea=%d\n", stack_a->size);
		// // printf("sizeb=%d\n", stack_b->size);
		// ft_rotate(stack_a);

		// ft_rotate(stack_b);
		// print_list(stack_a);
		// print_list(stack_b);
		// ft_push_b(stack_a, stack_b);
		// print_list(stack_a);
		// print_list(stack_b);
		// ft_reverse_rotate(stack_a);
		// // ft_reverse_rotate(stack_b);
		// print_list(stack_a);
		// print_list(stack_b);
		// check_order(stack_a);
		// // printf("\nLA\n");
		// ft_push_a(stack_a, stack_b);
		// print_list(stack_a);
		// print_list(stack_b);
		// ft_push_a(stack_a, stack_b);
		// print_list(stack_a);
		// print_list(stack_b);
		// if (ft_reverse_rotate(stack_a) != 0)
		// {
		// 	printf("firsta=%d\n", stack_a->first->nb);
		// 	return (1);
		// }
		// print_list(stack_a);
		// if (ft_rotate(stack_a) != 0)
		// {
		// 	printf("firsta=%d\n", stack_a->first->nb);
		// 	return (1);
		// }
		// printf("first=%d\n", stack_a->first->nb);
		// if (ft_swap_b(stack_b) != 0)
		// {
		// 	if (stack_b->first != NULL)
		// 		printf("firstb=%d\n", stack_b->first->nb);
		// 	return (1);
		// }
		// print_list(stack_a);
		// print_list(stack_b);



	// t_list **listb = create_empty_list(&stack);
	// (void)listb;
		// if (stack.a == NULL)
		// {
		// 	stack.a = fill_args_in_pile(ac, av, &stack);
		// }
		// if (stack.a == NULL)
		// 	return (0);
		// if (ft_double_int_in_tab(stack.a, stack.sizea) != 0)
		// 	return (1);
		// while (j < ac - 1)
		// {
		// 	// printf("stack=%d\n", stacka[j]);
		// 	// printf("j=%d\n", j);
		// 	j++;			
		// }
		// printf("\n");
		// ft_swap_a(&stack);
		// j = 0;
		// while (j < ac - 1)
		// {
		// 	printf("%d\n", stack.a[j]);
		// 	j++;			
		// }
		// printf("\n");
		// ft_reverse_rotate_a(&stack);
		// j = 0;
		// while (j < ac - 1)
		// {
		// 	printf("%d\n", stack.a[j]);
		// 	j++;			
		// }
		// free(stack.a);
// 	return (0);
// }
