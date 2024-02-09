/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctruchot <ctruchot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:11:47 by ctruchot          #+#    #+#             */
/*   Updated: 2024/02/09 14:03:12 by ctruchot         ###   ########.fr       */
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

void	print_list(t_list *stack)
{
	t_element	*actuel;

	if (stack == NULL)
	{
		return(ft_putstr_fd("LA", 2));
	}
	// printf("dd%ld\n", stack->first->nb);
	actuel = stack->first;
	while (actuel != NULL)
	{
		printf("%ld -> ", actuel->nb);
		actuel = actuel->next;
	}
	printf("NULL\n");
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

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("tab%s", tab[i]);
		i++;
	}
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
