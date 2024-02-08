/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctruchot <ctruchot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:10:06 by ctruchot          #+#    #+#             */
/*   Updated: 2024/02/08 18:36:58 by ctruchot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <stdbool.h> 

typedef struct s_element
{
	long int			nb;
	int					current_position;
	int					cost_to_top;
	bool				above_median;
	struct s_element	*target_node;
	struct s_element	*next;
}						t_element;

// necessaire d'avoir une tete de liste de type different ?
// possible de faire un pointeur head_a sur le premier element
// et tail_a sur le dernier ?

typedef struct s_list
{
	int					size;
	t_element			*first;
	// t_element			*last;
}						t_list;

int						check_double(t_list *stack);
int						check_int(char **av);
int						check_letters(char **av);
long int				ft_atoi(const char *nptr);
char					**ft_split(char const *s, char c);

t_element				*fill_args_in_stack_a(int ac, char **av);
t_list					*stack_a_init(int ac, char **av);
t_list					*stack_b_init(void);
int init_nodes_to_zero(t_element *element);


int						check_order(t_element *element);
int						order_three_a(t_list *stack);
int ft_algo(t_list *stack_a, t_list *stack_b);


int						ft_swap_a(t_list *stack);
int						ft_swap_b(t_list *stack);
int						ft_ss(t_list *stack_a, t_list *stack_b);
int						ft_push_a(t_list *stack_a, t_list *stack_b);
int						ft_push_b(t_list *stack_a, t_list *stack_b);
int						ft_rotate_a(t_list *stack);
int						ft_rotate_b(t_list *stack);
int						ft_rr(t_list *stack_a, t_list *stack_b);
int						ft_reverse_rotate_a(t_list *stack);
int						ft_reverse_rotate_b(t_list *stack);
int						ft_rrr(t_list *stack_a, t_list *stack_b);

t_element				*ft_lstnew(int nb);
t_element				*ft_lstlast(t_element *lst);
t_element				*ft_lstalmostlast(t_element *lst);
void					ft_lstadd_back(t_element **lst, t_element *new);
int						ft_lstsize(t_element *lst);

void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char *s, int fd);
void					print_list(t_list *stack_a);

int						free_list(t_list *stack_a);
int						free_tab(char **tab);

#endif
