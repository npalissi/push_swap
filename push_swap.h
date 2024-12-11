/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:01:51 by edubois-          #+#    #+#             */
/*   Updated: 2024/12/11 16:45:13 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "lib/printf/ft_printf.h"
# include "lib/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_data
{
	t_list	*stack_a;
	t_list	*stack_b;
}				t_data;

typedef struct s_op
{
	int	rra;
	int	rrb;
	int	rrr;
	int	ra;
	int	rb;
	int	rr;
}	t_op;

int		get_stack(char *str, t_list **stack);
void	clean_exit(t_list *a, int error);
void	ft_clearlst(t_list *a);
void	check_args(int ac, char **av);
void	check_for_dups(t_list *lst);
void	start_sort(t_list *lst);
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

void	ft_turkish_sort(t_data *data);
void	print_lst(t_list *a);

void	ft_quicksort(t_data *data);
void	ft_quicksort_four(t_data *data);
void	ft_quisort_five(t_data *data);
void	check_sort(t_list *lst);
void	print_lst(t_list *a); //a supp

t_op	ft_opti_rotate(t_op all_op);
t_op	ft_opti_rrotate(t_op all_op);
t_op	ft_opti_operations(t_op all_op, t_data *data);
int		ft_get_all_op(t_op *all_op);
void	ft_start_operation(t_op *all_op, t_data *data, char type_stack);

int		ft_get_pos(t_list *stack, t_list *node);
t_list	*ft_get_big(t_list *stack);
t_list	*ft_get_min(t_list *stack);
t_list	*ft_get_bigger(int content, t_list *stack);
t_list	*ft_get_smaller(int content, t_list *stack);

int		ft_get_pos(t_list *stack, t_list *node);
t_list	*ft_get_min(t_list *stack);

#endif 