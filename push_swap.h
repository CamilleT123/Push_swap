/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctruchot <ctruchot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:10:06 by ctruchot          #+#    #+#             */
/*   Updated: 2024/01/30 16:49:35 by ctruchot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>


void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);

int	ft_atoi(const char *nptr);
int	ft_double_int_in_tab(int *tab, int size);
int check_error(int *tab, int size);
int *fill_in_pile(int ac, char **av);





#endif
