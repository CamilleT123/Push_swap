/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_arguments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctruchot <ctruchot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:23:42 by ctruchot          #+#    #+#             */
/*   Updated: 2024/02/07 17:55:41 by ctruchot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*stack_b_init(void)
{
	t_list	*stack_b;

	stack_b = malloc(sizeof(*stack_b));
	if (stack_b == NULL)
	{
		exit(EXIT_FAILURE);
	}
	stack_b->first = NULL;
	stack_b->size = ft_lstsize(stack_b->first);
	return (stack_b);
}

t_list	*stack_a_init(int ac, char **av)
{
	t_list	*stack_a;

	if (check_letters(av) != 0)
		return (NULL);
	if (check_int(av) != 0)
		return (NULL);
	stack_a = malloc(sizeof(*stack_a));
	if (stack_a == NULL)
		exit(EXIT_FAILURE); // 		return (NULL);
	stack_a->first = NULL;
	stack_a->first = fill_args_in_stack_a(ac, av);
	if (check_double(stack_a) != 0)
	{
		free_list(stack_a);
		free_tab(av);
		exit (1);
	}
	stack_a->size = ft_lstsize(stack_a->first);
	return (stack_a);
}

t_element	*fill_args_in_stack_a(int ac, char **av)
{
	int			i;
	int			j;
	t_element	*element;

	i = 1;
	j = 0;
	element = ft_lstnew(ft_atoi(av[i]));
	if (element == NULL)
		return (NULL);
	while (i < ac - 1)
	{
		i++;
		ft_lstadd_back(&element, ft_lstnew(ft_atoi(av[i])));
	}
	return (element);
}

// void	fill_string_in_pile(char *av, t_stack *stack)
// {
// 	int		i;
// 	char	**tab;
// 	int		j;

// 	j = 0;
// 	i = 0;
// 	tab = ft_split(&av[i], ' ');

// 	while (tab[i])
// 		i++;
// 	stack->sizea = i;
// 	stack->a = malloc(sizeof(int) * i);
// 	while (i > 0)
// 	{
// 		i--;
// 		while (tab[i][j])
// 		{
// 			if ((tab[i][j] < '0' || tab[i][j] > '9') && tab[i][j] != ' ')
// 			{
// 				ft_putstr_fd("Error2\n", 2);
// 				exit(0);
// 			}
// 			j++;
// 		}
// 		stack->a[i] = ft_atoi(tab[i]);
// 		// printf("%d\n", stacka[i]);
// 	}
// 	// return (stack->a);
// }

// t_list	**fill_args_in_pile(int ac, char **av, t_stack *stack)
// {
// 	t_control *control = control_init();
// 	insertion(control, nb);
// 	t_list **lista;
// 	int	i;
// 	int	j;

// 	i = 1;// void insertion(t_list *stack_a, int nvNombre)
// {
//     t_element *new = malloc(sizeof(*new));
	// pourquoi pas malloc de t_element?
//     if (stack_a == NULL || new == NULL)
//     {
//         exit(EXIT_FAILURE);
//     }
//     new->nb = nvNombre;
// 	new->next = NULL;

//     new->next = stack_a->first;
//     stack_a->first = new;
// }
// 	j = 0;
// 	stack->sizea = ac - 1;
// 	lista = malloc(sizeof(t_list *));
// 	t_list *element = ft_lstnew(ft_atoi(av[i]));
// 	*lista = element;
// 	while (i < stack->sizea)
// 	{
// 		while (av[i][j])
// 		{
// 			if ((av[i][j] < '0' || av[i][j] > '9') && av[i][j] != ' ')
// 				return (ft_putstr_fd("Error\n", 2), NULL);
// 			j++;
// 		}
// 		i++;
// 		ft_lstadd_back(lista, ft_lstnew(ft_atoi(av[i])));
// 	}
// 	return (lista);
// }

// t_list	**create_empty_list(t_stack *stack)
// {
// 	t_list **listb;
// 	// int nb;
// 	int i = 0;

// 	listb = malloc(sizeof(t_list *));
// 	t_list *element = ft_lstnew(NULL);
// 	*listb = element;
// 	while (i < stack->sizea)
// 	{
// 		i++;
// 		ft_lstadd_back(listb, ft_lstnew(NULL));
// 	}
// 	return (listb);
// }

// void insertion(t_list *stack_a, int nvNombre)
// {
//     t_element *new = malloc(sizeof(*new));
	// pourquoi pas malloc de t_element?
//     if (stack_a == NULL || new == NULL)
//     {
//         exit(EXIT_FAILURE);
//     }
//     new->nb = nvNombre;
// 	new->next = NULL;

//     new->next = stack_a->first;
//     stack_a->first = new;
// }