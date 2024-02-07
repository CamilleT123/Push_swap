/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctruchot <ctruchot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:55:29 by ctruchot          #+#    #+#             */
/*   Updated: 2024/02/07 17:55:54 by ctruchot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(t_list *stack)
{
	t_element	*element;
	t_element	*element2;
	int			nb;

	element = NULL;
	element2 = NULL;
	element = stack->first;
	while (element)
	{
		element2 = element->next;
		nb = element->nb;
		while (element2)
		{
			if (nb == element2->nb)
			{
				ft_putstr_fd("Error\n", 2);
				return (1);
			}
			element2 = element2->next;
		}
		element = element->next;
	}
	return (0);
}

int	check_int(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_atoi(av[i]) > 2147483647)
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_letters(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] < '0' || av[i][j] > '9') && ((av[i][j] < 9
						|| av[i][j] > 13) && av[i][j] != 32 && av[i][j] != '-'
					&& av[i][j] != '+'))
				return (ft_putstr_fd("Error\n", 2), 1);
			if (av[i][j + 1] && (av[i][j] == '-' || av[i][j] == '+') && (av[i][j
					+ 1] == '-' || av[i][j + 1] == '+'))
				return (ft_putstr_fd("Error\n", 2), 1);
			j++;
		}
		i++;
	}
	return (0);
}
