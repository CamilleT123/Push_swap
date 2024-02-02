/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctruchot <ctruchot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:34:09 by ctruchot          #+#    #+#             */
/*   Updated: 2024/02/02 19:29:00 by ctruchot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// En cas d’erreur,
	// vous devez afficher "Error" suivi d’un ’\n’ sur la sortie d’erreur.
// Par exemple, si certains paramètres ne sont pas des nombres,
	// ne tiennent pas dans
// un int, ou encore, s’il y a des doublons.

#include "push_swap_list.h"
#include <stdio.h>

int	check_error(int *tab, int size)
{
	if (ft_double_int_in_tab(tab, size) != 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	return (0);
}


int	main(int ac, char **av)
{
	t_stack stack;
	
	int	i;
	// int j = 0;

	i = 0;
	// printf("test00\n");
	stack.a = NULL;
	if (ac < 2) // Si aucun paramètre n’est spécifié,
		// le programme ne doit rien afficher et rendre
				// l’invite de commande.
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	// if (ac >= 2)
	// {
	// 	while (av[1][i] != '\0')
	// 	{
	// 		if (av[1][i] == ' ')
	// 		{
	// 			// printf("test01\n");
	// 			stack.a = fill_string_in_pile(av[1], &stack); // gerer la gestion d'erreur
	// 			break ;
	// 		}
	// 		i++;
	// 	}
	t_list **lista = fill_args_in_pile(ac, av, &stack);
	t_list **listb = create_empty_list(&stack);
	(void)lista;
	(void)listb;
		// if (stack.a == NULL)
		// {
		// 	stack.a = fill_args_in_pile(ac, av, &stack);
		// }
		// if (stack.a == NULL)
		// 	return (0);
		// if (ft_double_int_in_tab(stack.a, stack.sizea) != 0)
		// 	return (1);
		// while (j < ac - 1)
		// {
		// 	// printf("stack=%d\n", stacka[j]);
		// 	// printf("j=%d\n", j);
		// 	j++;			
		// }
		// printf("\n");
		// ft_swap_a(&stack);
		// j = 0;
		// while (j < ac - 1)
		// {
		// 	printf("%d\n", stack.a[j]);
		// 	j++;			
		// }
		// printf("\n");
		// ft_reverse_rotate_a(&stack);
		// j = 0;
		// while (j < ac - 1)
		// {
		// 	printf("%d\n", stack.a[j]);
		// 	j++;			
		// }
		// free(stack.a);
	return (0);
}
