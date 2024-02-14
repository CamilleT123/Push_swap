/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctruchot <ctruchot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:39:12 by ctruchot          #+#    #+#             */
/*   Updated: 2024/02/12 17:44:13 by ctruchot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// impression d'un char et renvoi de 1

int	print_char(int i)
{
	char	c;

	c = i;
	return (write(1, &c, 1));
}

// impression d'une chaine de char et retourne le nombre de char imprimes
// si la chaine n'existe pas,
// impression de (null) et renvoi du nombre de char correspondant comme printf

int	print_str(char *str)
{
	int	written;

	written = 0;
	if (!str)
	{
		print_str("(null)");
		return (6);
	}
	while (*str)
	{
		written += write(1, str, 1);
		str++;
	}
	return (written);
}

// si le pointer est null, la fonction fprint renvoie (nil) et le nombre de
// char correspondants. Impression manuelle de 0x, puis de l'int en hexa

int	print_pointer(unsigned long int pointer)
{
	int	count;

	if (pointer == 0)
	{
		print_str("(nil)");
		return (5);
	}
	count = print_str("0x");
	count += print_nbr_hexa(pointer, 0);
	return (count);
}

// check the character after the % and calls the function corresponding to the
// type. Each function returns the count of elements written
// va_arg extracts the following parameter of the type indicated as 2nd param

int	print_format(char type, va_list args)
{
	if (type == 'c')
		return (print_char(va_arg(args, int)));
	else if (type == 's')
		return (print_str(va_arg(args, char *)));
	else if (type == 'p')
		return (print_pointer(va_arg(args, unsigned long int)));
	else if (type == 'd')
		return (print_nbr(va_arg(args, int)));
	else if (type == 'i')
		return (print_nbr(va_arg(args, int)));
	else if (type == 'u')
		return (print_nbr_unsigned(va_arg(args, unsigned int)));
	else if (type == 'x')
		return (print_nbr_hexa((unsigned long)va_arg(args, unsigned int), 0));
	else if (type == 'X')
		return (print_nbr_hexa((unsigned long)va_arg(args, unsigned int), 1));
	else if (type == '%')
		return (print_char(37));
	else
	{
		print_char('%');
		print_char(type);
		return (2);
	}
	return (0);
}

// va_list args defines args of type va_list
// va_start(args, format) initialises the structure	va_list	to use the
// parameters following the last named param (format) in the function
// countwritten counts the elements written by the function
// checks that there is a first argument given to the function,
// otherwise return -1.
// while the first argument string exists, the function checks if there is a %
// if there is a %, it send the next character to print_format
// and adds the return of this function to countwritten
// if there is no %, then the function writes the first argument characters
// va_end(args) frees the resources;

int	ft_printf(const char *format, ...)
{
	int		countwritten;
	va_list	args;
	int		i;

	va_start(args, format);
	countwritten = 0;
	i = 0;
	if (!format)
		return (-1);
	while (format[i] != 0)
	{
		if (format[i] == '%' && format[i + 1] == '\0')
			return (va_end(args), -1);
		else if (format[i] == '%')
		{
			i++;
			countwritten += print_format(format[i], args);
		}
		else
			countwritten += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (countwritten);
}
// #include <stddef.h>
// #include <limits.h>

// int	main(void)
// {
// // 	// int a = 10;
// // 	// int *b = &a;
// // 	int i;
// // 	int j;

// // 	// i = ft_printf("%x&%x\n", 0, -42);
// // 	// j = printf("%x&%x\n", 0, -42);
// // 	i = ft_printf(" %d ", INT_MIN);
// // 	j = printf(" %d ", INT_MIN);
// // i = ft_printf(" %d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX,
		// LONG_MIN,
// // 		ULONG_MAX, 0, -42);
// // j = printf(" %d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN,
// // 		ULONG_MAX, 0, -42);
// // 	// i = ft_printf(0);
// // 	// j = printf( 0);

// // // 	printf("\ni=%d, j= %d\n", i, j);
// // // }

// }