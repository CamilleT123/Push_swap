/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctruchot <ctruchot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:04:49 by ctruchot          #+#    #+#             */
/*   Updated: 2024/02/02 19:11:32 by ctruchot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_list.h"


int	ft_atoi(const char *nptr)
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
	if (nptr[i] < '0' || nptr[i] > '9')
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		r = r * 10 + nptr[i] - 48;
		i++;
	}
	if (rneg == -1)
		r = r * -1;
	if (r > 2147483647 || r < -2147483648)
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	return (r);
}
