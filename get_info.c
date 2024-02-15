/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctruchot <ctruchot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:29:03 by ctruchot          #+#    #+#             */
/*   Updated: 2024/02/15 17:25:24 by ctruchot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_above_median(t_element *element, t_list *stack)
{
	int	median;

	if (stack->size % 2 == 0)
		median = stack->size / 2;
	else
		median = stack->size / 2 + 1;
	if (element->position < median)
		element->above_median = true;
	else
		element->above_median = false;
	return (0);
}

t_element	*identify_smallest(t_list *stack)
{
	t_element	*element;
	t_element	*smallest;

	element = stack->first;
	smallest = malloc(sizeof(t_element));
	smallest->nb = INT_MAX;
	smallest->next = NULL;
	while (element)
	{
		if (element->nb < smallest->nb)
		{
			if (smallest->nb == INT_MAX)
				free(smallest);
			smallest = element;
		}
		element = element->next;
	}
	return (smallest);
}

t_element	*identify_biggest(t_list *stack)
{
	t_element	*element;
	t_element	*biggest;

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
	return (biggest);
}

int	identify_position(t_element *element_x, t_element *element)
{
	int	i;

	i = 0;
	while (element != element_x)
	{
		i++;
		element = element->next;
	}
	element_x->position = i;
	return (0);
}
