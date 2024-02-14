/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctruchot <ctruchot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:50:21 by ctruchot          #+#    #+#             */
/*   Updated: 2024/02/12 17:44:07 by ctruchot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// print numbers in 10 base. if number is neg, prints de symbol first and
// recalls the function with -nbr.
// the function calls itself with nbr/10 as long as number is above 10
// and count counts the number of function calls

int	print_nbr(long int nbr)
{
	char	*b;
	int		count;

	b = "0123456789";
	if (nbr < 0)
		return (write(1, "-", 1) + print_nbr(-nbr));
	if (nbr < 10)
		return (print_char(b[nbr]));
	count = print_nbr(nbr / 10);
	count += print_nbr(nbr % 10);
	return (count);
}

// same as above but with an unsigned int so negative numbers are not covered

int	print_nbr_unsigned(unsigned int nbr)
{
	char	*b;
	int		count;

	b = "0123456789";
	if (nbr < 10)
		return (print_char(b[nbr]));
	count = print_nbr_unsigned(nbr / 10);
	count += print_nbr_unsigned(nbr % 10);
	return (count);
}

// same as above, but with a 16 base. the function covers both situations 
// of upper or lower case : int maj is 0 or 1 depending on the situation

int	print_nbr_hexa(unsigned long int nbr, int maj)
{
	char	*b;
	char	*c;
	int		count;

	b = "0123456789abcdef";
	c = "0123456789ABCDEF";
	if (nbr < 16)
	{
		if (maj == 0)
			return (print_char(b[nbr]));
		if (maj == 1)
			return (print_char(c[nbr]));
	}
	count = print_nbr_hexa(nbr / 16, maj);
	return (count + print_nbr_hexa(nbr % 16, maj));
}
