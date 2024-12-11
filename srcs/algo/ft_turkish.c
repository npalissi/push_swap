/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turkish.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:45:20 by npalissi          #+#    #+#             */
/*   Updated: 2024/12/11 16:30:31 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_op	ft_get_best_op(t_data *data, t_list *tmp, t_list *stack1,
		t_list *stack2)
{
	t_op	tmp_op;

	tmp_op = (t_op){0, 0, 0, 0, 0, 0};
	tmp_op.ra = ft_get_pos(stack1, tmp);
	tmp_op.rb = ft_get_pos(stack2, ft_get_smaller(tmp->content, stack2));
	tmp_op = ft_opti_operations(tmp_op, data);
	return (tmp_op);
}

void	ft_pushb(t_data *data)
{
	t_op	opt;
	int		size;
	t_list	*min_node;

	opt = (t_op){0, 0, 0, 0, 0, 0};
	while (ft_lstsize(data->stack_b))
	{
		opt.ra = ft_get_pos(data->stack_a, ft_get_bigger(data->stack_b->content,
					data->stack_a));
		ft_start_operation(&opt, data, 'b');
	}
	min_node = ft_get_min(data->stack_a);
	if (ft_get_pos(data->stack_a, min_node) > ft_lstsize(data->stack_a) / 2)
		size = 1;
	else
		size = 0;
	while (data->stack_a != min_node)
	{
		if (size)
			rra(data, 1);
		else
			ra(data, 1);
	}
}

void	ft_turkish_sort(t_data *data)
{
	t_list	*tmp;
	t_op	all_op;
	t_op	tmp_op;
	int		min_ops;

	pb(data, 1);
	pb(data, 1);
	while (ft_lstsize(data->stack_a) > 1)
	{
		tmp = data->stack_a;
		min_ops = INT_MAX;
		all_op = (t_op){0, 0, 0, 0, 0, 0};
		while (tmp)
		{
			tmp_op = ft_get_best_op(data, tmp, data->stack_a, data->stack_b);
			if (ft_get_all_op(&tmp_op) < min_ops)
			{
				min_ops = ft_get_all_op(&tmp_op);
				all_op = tmp_op;
			}
			tmp = tmp->next;
		}
		ft_start_operation(&all_op, data, 'a');
	}
	ft_pushb(data);
}
