/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_arguments_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctruchot <ctruchot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:23:42 by ctruchot          #+#    #+#             */
/*   Updated: 2024/02/02 19:29:54 by ctruchot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_list.h"
#  define NULL ((void*)0)

t_list	*ft_lstnew(int nb)
{
	t_list	*element;

	element = malloc(sizeof(t_list));
	if (element == NULL)
		return (NULL);
	element->nb = nb;
	element->next = NULL;
	return (element);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if ((*lst) == NULL)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}
t_list	**create_empty_list(t_stack *stack)
{
	t_list **listb;
	// int nb;
	int i = 0;
	
	listb = malloc(sizeof(t_list *));
	t_list *element = ft_lstnew(NULL); 
	*listb = element;
	while (i < stack->sizea)
	{
		i++;
		ft_lstadd_back(listb, ft_lstnew(NULL));
	}
	return (listb);
}

t_list	**fill_args_in_pile(int ac, char **av, t_stack *stack)
{
	t_list **lista;
	int	i;
	int	j;

	i = 1;
	j = 0;
	stack->sizea = ac - 1;
	lista = malloc(sizeof(t_list *));
	// stack->a = malloc(sizeof(int) * stack->sizea);
	t_list *element = ft_lstnew(ft_atoi(av[i])); 
	*lista = element;
	while (i < stack->sizea)
	{
		while (av[i][j])
		{
			if ((av[i][j] < '0' || av[i][j] > '9') && av[i][j] != ' ')
				return (ft_putstr_fd("Error\n", 2), NULL);
			j++;
		}
		i++;
		ft_lstadd_back(lista, ft_lstnew(ft_atoi(av[i])));
	}
	return (lista);
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
