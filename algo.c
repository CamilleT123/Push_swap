/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctruchot <ctruchot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:43:29 by ctruchot          #+#    #+#             */
/*   Updated: 2024/02/07 13:55:04 by ctruchot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

// Check if the order of the list is correct or if it should be sorted

// int ft_is_min(t_list *stack)
// {
// 	t_element *element;
// 	element = stack->first;
	
// 	long int min = LONG_MAX;
// 	printf("min=%ld\n", min);
// 	if (!element)
// 		return (1);
// 	if (element->nb < element->next->nb)
// 			min = element->nb;
// 	while (element)
// 	{
// 		if (min > element->nb)
// 			min = element->nb;
// 		printf("min=%ld\n", min);
// 		element = element->next;
// 	}
// 	return (min);
// }

#include <limits.h>

t_element *is_max(t_list *stack)
{
	t_element *element;
	element = stack->first;
	t_element *biggest;
	biggest = NULL;
	if (!element)
		return (NULL);
	if (element->nb > element->next->nb)
			biggest = element;
	else
		biggest = element->next;
	while (element->next)
	{
		element = element->next;
		if (biggest->nb < element->nb)
			biggest = element;
	}
	// printf("biggest3=%d\n", biggest->nb);
	return (biggest);
}

int order_three_a(t_list *stack)
{
	t_element *biggest;
	biggest = is_max(stack);
	if (biggest == stack->first)
		ft_rotate_a(stack);
	else if (biggest == stack->first->next)
		ft_reverse_rotate_a(stack);
	if (stack->first->nb > stack->first->next->nb)
		ft_swap_a(stack);
	return (0);
}

int check_order(t_element *element)
{
	if (!element)
		return (1);
	while (element->next)
	{
		if (element->nb > element->next->nb)
			return (-1);
		element = element->next;
	}
	return (0);
}


// find the min and max
//  pointeur sur le last A and B 
// bool ??
// index, above median, cheapest + poineur sur target node

// algo if 2 algo if 3 algo for more