/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:54:26 by edubois-          #+#    #+#             */
/*   Updated: 2024/12/11 16:33:34 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../lib/printf/ft_printf.h"
# include "../lib/libft/libft.h"
# include "../lib/gnl/get_next_line.h"

typedef struct s_data
{
	t_list	*stack_a;
	t_list	*stack_b;
}				t_data;

int		sa(t_data *data, int send_message);
int		ra(t_data *data, int send_message);
int		rra(t_data *data, int send_message);
int		pa(t_data *data, int send_message);
int		sb(t_data *data, int send_message);
int		rb(t_data *data, int send_message);
int		rrb(t_data *data, int send_message);
int		pb(t_data *data, int send_message);
int		rba(t_list **stack);
int		sba(t_list **stack);
int		rrba(t_list **stack);
int		pba(t_list **stack_1, t_list **stack_2);
void	ss(t_data *data, int send_message);
void	rr(t_data *data, int send_message);
void	rrr(t_data *data, int send_message);
void	ft_clearlst(t_list *a);
int		get_stack(char *str, t_list **stack);
int		main(int ac, char **av);
void	clean_exit_bonus(t_list *a, int error);
void	check_for_letters(char **av, int ac);
void	check_for_sign(char **av, int ac);
void	check_for_dups(t_list *lst);
void	check_args(int ac, char **av);

#endif