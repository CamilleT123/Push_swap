/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_arguments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctruchot <ctruchot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:23:42 by ctruchot          #+#    #+#             */
/*   Updated: 2024/02/15 17:18:13 by ctruchot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// when argument is a string, creates an array with the numbers of the string
// and send it to stack_a_init as if it was arguments
// first string of the array is empty to simulate arguments where 
// the first one is the exec file

t_list	*parsing_string(char **av, t_list *stack_a)
{
	char	**strarg;
	int		i;

	i = 0;
	strarg = NULL;
	strarg = ft_split(av[1], ' ');
	if (strarg == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	while (strarg[i])
		i++;
	stack_a = stack_a_init(i, strarg, 1);
	free_tab(strarg);
	return (stack_a);
}

// initialize stack_a list head, checks the errors in the arguments
//  and each node of the list based on the arguments
// using the fill_args_in_stack_a function

t_list	*stack_a_init(int ac, char **av, int string)
{
	t_list	*stack_a;

	stack_a = NULL;
	if (check_letters(av) != 0 || check_int(av) != 0)
	{
		if (string == 1)
			free_tab(av);
		exit (1);
	}
	stack_a = malloc(sizeof(*stack_a));
	if (stack_a == NULL)
		exit (1);
	stack_a->first = NULL;
	stack_a->first = fill_args_in_stack_a(ac, av);
	if (stack_a->first == NULL || check_double(stack_a) != 0)
	{
		if (string == 1)
			free_tab(av);
		free_list(stack_a);
		exit (1);
	}
	stack_a->biggest = identify_biggest(stack_a);
	stack_a->size = ft_lstsize(stack_a->first);
	return (stack_a);
}

// fill the nodes with the numbers in argument
// initiates the rest of the data to 0 with init_nodes_to_zero
//  included in the lstnew

t_element	*fill_args_in_stack_a(int ac, char **av)
{
	int			i;
	t_element	*element;

	i = 1;
	element = ft_lstnew(ft_atoi(av[i]));
	if (element == NULL)
		return (NULL);
	while (i < ac - 1)
	{
		i++;
		if (ft_lstadd_back(&element, ft_lstnew(ft_atoi(av[i]))) != 0)
			return (NULL);
	}
	return (element);
}

// initiates the rest of the data of the nodes to 0 or NULL

int	init_nodes_to_zero(t_element *element)
{
	element->position = 0;
	element->cost_top = 0;
	element->cost_target = 0;
	element->above_median = false;
	element->target_node = NULL;
	return (0);
}

// initializes the stack_b head list, the list remains empty for now

t_list	*stack_b_init(t_list *stack_a)
{
	t_list	*stack_b;

	stack_b = malloc(sizeof(*stack_b));
	if (stack_b == NULL)
	{
		free_list(stack_a);
		exit (1);
	}
	stack_b->first = NULL;
	stack_b->size = ft_lstsize(stack_b->first);
	return (stack_b);
}
