/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctruchot <ctruchot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:10:06 by ctruchot          #+#    #+#             */
/*   Updated: 2024/02/14 17:58:19 by ctruchot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
// # include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_element
{
	long int			nb;
	int					position;
	int					cost_top;
	int					cost_target;
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
	t_element			*biggest;
	t_element			*first;
}						t_list;

t_list				*parsing_string(char **av, t_list *stack_a);
t_list				*stack_a_init(int ac, char **av);
t_list				*stack_b_init(t_list *stack_a);
t_element			*fill_args_in_stack_a(int ac, char **av);
int					init_nodes_to_zero(t_element *element);

int					check_double(t_list *stack);
int					check_int(char **av);
int					check_letters(char **av);

int					check_order(t_element *element);
int					order_three_a(t_list *stack_a, t_list *stack_b);
int					ordering_first_part(t_list *stack_a, t_list *stack_b);
int					ordering_second_part(t_list *stack_a, t_list *stack_b);

int					move_together(t_element *cheapest, t_list *stack_a,
						t_list *stack_b);
int					finish_move(t_element *cheapest, t_list *stack_a,
						t_list *stack_b);
int					move_nodes(t_element *cheapest, t_list *stack_a,
						t_list *stack_b);

int					stack_a_fill_info(t_list *stack_a);
int					stack_b_fill_info(t_list *stack_b, t_list *stack_a);
int					update_stacks_info(t_list *stack_a, t_list *stack_b);

int					is_above_median(t_element *element, t_list *stack);
t_element			*identify_smallest(t_list *stack);
t_element			*identify_biggest(t_list *stack);
int					identify_position(t_element *element_x, t_element *element);
int					calculate_cost_top(t_element *element, t_list *stack);
int					calculate_cost_target(t_element *element);
int					identify_target_node(t_element *element_b,
						t_list *stack_a);
t_element			*identify_cheapest(t_list *stack);

int					ft_swap_a(t_list *stack_a, t_list *stack_b, int call);
int					ft_swap_b(t_list *stack_a, t_list *stack_b, int call);
int					ft_ss(t_list *stack_a, t_list *stack_b);
int					ft_push_a(t_list *stack_a, t_list *stack_b);
int					ft_push_b(t_list *stack_a, t_list *stack_b);
int					ft_rotate_a(t_list *stack_a, t_list *stack_b, int call);
int					ft_rotate_b(t_list *stack_a, t_list *stack_b, int call);
int					ft_rr(t_list *stack_a, t_list *stack_b);
int					ft_reverse_rotate_a(t_list *stack_a, t_list *stack_b,
						int call);
int					ft_reverse_rotate_b(t_list *stack_a, t_list *stack_b,
						int call);
int					ft_rrr(t_list *stack_a, t_list *stack_b);

t_element			*ft_lstnew(int nb);
t_element			*ft_lstlast(t_element *lst);
int					ft_lstadd_back(t_element **lst, t_element *new);
t_element			*ft_lstalmostlast(t_element *lst);
int					ft_lstsize(t_element *lst);

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
long int			ft_atoi(const char *nptr);
int					free_tab(char **tab);

int					free_list(t_list *stack_a);

char				**ft_split(char const *s, char c);

int					print_char(int i);
int					print_str(char *str);
int					print_nbr(long int nbr);
int					print_nbr_unsigned(unsigned int nbr);
int					print_nbr_hexa(unsigned long int nbr, int maj);
int					print_pointer(unsigned long int pointer);
int					print_format(char type, va_list args);
int					ft_printf(const char *format, ...);

void				print_list(t_list *stack_a); // suppriner
#endif
