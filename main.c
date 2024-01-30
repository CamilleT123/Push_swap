/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctruchot <ctruchot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:34:09 by ctruchot          #+#    #+#             */
/*   Updated: 2024/01/30 16:52:13 by ctruchot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// En cas d’erreur, vous devez afficher "Error" suivi d’un ’\n’ sur la sortie d’erreur.
// Par exemple, si certains paramètres ne sont pas des nombres, ne tiennent pas dans
// un int, ou encore, s’il y a des doublons.

#include "push_swap.h"
#include <stdio.h>

int check_error(int *tab, int size)
{
	if (ft_double_int_in_tab(tab, size) != 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	return (0);
}

int *fill_in_pile(int ac, char **av)
{
	int i;
	int *tab;
	
	i = 1;
	tab = malloc(sizeof(int) * (ac - 1));
	// printf("%d\n", (ac - 1));
	while (av[i])
	{
		tab[i - 1] = ft_atoi(av[i]);
		printf("%d\n", tab[i - 1]);
		// if ((tab[i - 1]) == 0)
		// 	ft_putstr_fd("Error\n", 2);
		i++;
	}
	return (tab);
}

int main(int ac, char **av)
{
	int *tab;
	int size;

	size = ac - 1;

	if (ac < 2) // Si aucun paramètre n’est spécifié, le programme ne doit rien afficher et rendre
			// l’invite de commande.
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (ac >= 2)
	{
		tab = fill_in_pile(ac, av);
		if (ft_double_int_in_tab(tab, size) != 0)
			return (1);
		free(tab);
	}
	return (0);
}
