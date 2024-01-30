/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctruchot <ctruchot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:11:47 by ctruchot          #+#    #+#             */
/*   Updated: 2024/01/30 16:48:35 by ctruchot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
#include <stdio.h>

int	ft_double_int_in_tab(int *tab, int size)
{
	int	i;
	int j;

	i = 1;
	j = 0;
	// printf("size%d\n", size);
	while (i < size)
	{
		while (j < i)
		{
			if (tab[i] == tab[j])
			// {
			// 	printf("tab[%d]= %d\n", i, tab[i]);
			// 	printf("tab[%d]= %d\n", j, tab[j]);
				return (ft_putstr_fd("Error\n", 2), 1);
			// }
			else
				j++;
		}
		i++;
		j = 0;
	}
	return (0);
}