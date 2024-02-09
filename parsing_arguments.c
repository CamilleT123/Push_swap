/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_arguments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctruchot <ctruchot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:23:42 by ctruchot          #+#    #+#             */
/*   Updated: 2024/02/09 14:21:54 by ctruchot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// initialize stack_a list head, checks the errors in the arguments
//  and each nodes of the list based on the arguments 
// and the fill_args_in_stack_a function

t_list	*stack_a_init(int ac, char **av)
{
	t_list	*stack_a;

	stack_a = NULL;
	if (check_letters(av) != 0)
		return (NULL);
	if (check_int(av) != 0)
		return (NULL);
	stack_a = malloc(sizeof(*stack_a));
	if (stack_a == NULL)
	{
		return(ft_putstr_fd("LA", 2), NULL);
	}	
	stack_a->first = NULL;
	stack_a->first = fill_args_in_stack_a(ac, av);
	// print_list(stack_a);
	if (check_double(stack_a) != 0)
	{
		free_list(stack_a);
		free_tab(av);
		exit (1);
	}
	// printf("%ld\n", stack_a->first->nb);
	// printf("%ld\n", stack_a->first->next->nb);
	// printf("%ld\n", stack_a->first->next->next->nb);
	// stack_a->biggest = identify_biggest(stack_a);
	stack_a->size = ft_lstsize(stack_a->first);
	return (stack_a);
}

// fill the nodes with the numbers in argument
// initiates the rest of the data to 0 with init_nodes_to_zero
//  included in the lstnew

t_element	*fill_args_in_stack_a(int ac, char **av)
{
	int			i;
	int			j;
	t_element	*element;

	i = 1;
	j = 0;
	element = ft_lstnew(ft_atoi(av[i]));
	// printf("element=%ld\n", element->nb);
	if (element == NULL)
		return (NULL);
	while (i < ac - 1)
	{
		i++;
		ft_lstadd_back(&element, ft_lstnew(ft_atoi(av[i])));
	}
	// printf("element=%ld\n", element->nb);
	return (element);
}

// initiates the rest of the data of the nodes to 0

int	init_nodes_to_zero(t_element *element)
{
	element->current_position = 0;
	element->cost_to_top = 0;
	element->cost_to_target = 0;
	element->above_median = false;
	element->target_node = NULL;
	return (0);
}

// initializes the stack_b head list, the list remains empty for now

t_list	*stack_b_init(void)
{
	t_list	*stack_b;

	stack_b = malloc(sizeof(*stack_b));
	if (stack_b == NULL)
	{
		return(ft_putstr_fd("LA", 2), NULL);
	}
	stack_b->first = NULL;
	stack_b->size = ft_lstsize(stack_b->first);
	// printf("size_b=%d\n", stack_b->size);
	// printf("first=%p\n", stack_b->first);
	return (stack_b);
}

t_element	*identify_biggest(t_list *stack)
{
	t_element *element;
	t_element *biggest;
	
	element = stack->first;
	biggest = malloc(sizeof(t_element));
	biggest->nb = INT_MIN;
	biggest->next = NULL;
	while (element)
	{
		if (element->nb > biggest->nb)
		{
			if (biggest->nb == INT_MIN)
				free(biggest);
			biggest = element;
		}
		element = element->next;
	}
	// printf("biggest=%ld\n", biggest->nb);
	return (biggest);
}
