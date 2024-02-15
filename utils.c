/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctruchot <ctruchot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:11:47 by ctruchot          #+#    #+#             */
/*   Updated: 2024/02/15 12:36:33 by ctruchot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

long int	ft_atoi(const char *nptr)
{
	long int	r;
	int			rneg;
	int			i;

	r = 0;
	i = 0;
	rneg = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			rneg = rneg * -1;
		i++;
	}
	while (nptr[i])
	{
		r = r * 10 + nptr[i] - 48;
		i++;
	}
	if (rneg == -1)
		r = r * -1;
	if (r > 2147483647 || r < -2147483648)
		return (2147483649);
	return (r);
}

int	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

int	free_list(t_list *stack)
{
	t_element	*last;
	t_element	*almostlast;

	last = NULL;
	almostlast = NULL;
	if (stack->first == NULL)
		return (free(stack), 1);
	while (stack->first->next != NULL)
	{
		last = ft_lstlast(stack->first);
		almostlast = ft_lstalmostlast(stack->first);
		almostlast->next = NULL;
		free(last);
	}
	free(stack->first);
	free(stack);
	return (0);
}

// // a supprimer
// void	print_list(t_list *stack)
// {
// 	t_element	*actuel;

// 	if (stack == NULL)
// 	{
// 		return (ft_putstr_fd("LA", 2));
// 	}
// 	actuel = stack->first;
// 	while (actuel != NULL)
// 	{
// 		printf("%ld -> ", actuel->nb);
// 		actuel = actuel->next;
// 	}
// 	printf("NULL\n");
// }
