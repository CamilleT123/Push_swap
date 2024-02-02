/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctruchot <ctruchot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:10:06 by ctruchot          #+#    #+#             */
/*   Updated: 2024/02/02 19:08:59 by ctruchot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>


typedef struct s_stack
{
	int *a;
	int sizea;
	int *b;
	int sizeb;
} t_stack;

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);

int		ft_atoi(const char *nptr);

int		ft_double_int_in_tab(int *tab, int size);

int		check_error(int *tab, int size);
int		*fill_args_in_pile(int ac, char **av, t_stack *stack);
int		*fill_string_in_pile(char *av, t_stack *stack);

void ft_swap_a(t_stack *stack);
void ft_rotate_a(t_stack *stack);
void ft_reverse_rotate_a(t_stack *stack);


char	**ft_split(char const *s, char c);
// static char	*ft_createlines(const char *s, char c);
// static char	**ft_freetab(char **tab);
// static int	ft_countwords(const char *s, char c);

#endif
