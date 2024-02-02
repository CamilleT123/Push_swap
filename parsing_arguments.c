/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_arguments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctruchot <ctruchot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:23:42 by ctruchot          #+#    #+#             */
/*   Updated: 2024/02/01 15:36:45 by ctruchot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*fill_args_in_pile(int ac, char **av, t_stack *stack)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	stack->sizea = ac - 1;
	stack->a = malloc(sizeof(int) * stack->sizea);
	while (av[i])
	{
		while (av[i][j])
		{
			if ((av[i][j] < '0' || av[i][j] > '9') && av[i][j] != ' ')
				return (ft_putstr_fd("Error\n", 2), NULL);
			j++;
		}
		stack->a[i - 1] = ft_atoi(av[i]);
		printf("%d\n", stack->a[i - 1]);
		i++;
	}
	return (stack->a);
}

int	*fill_string_in_pile(char *av, t_stack *stack)
{
	int		i;
	char	**tab;
	int		j;

	
	j = 0;
	i = 0;
	tab = ft_split(&av[i], ' ');
	while (tab[i])
		i++;
	stack->sizea = i;
	stack->a = malloc(sizeof(int) * i);
	while (i > 0)
	{
		i--;
		while (tab[i][j])
		{
			if ((tab[i][j] < '0' || tab[i][j] > '9') && tab[i][j] != ' ')
			{
				ft_putstr_fd("Error2\n", 2);
				exit(0);
			}
			j++;
		}
		stack->a[i] = ft_atoi(tab[i]);
		// printf("%d\n", stacka[i]);
	}
	return (stack->a);
}
