/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:28:44 by npalissi          #+#    #+#             */
/*   Updated: 2024/12/11 14:06:16 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_op	ft_opti_rotate(t_op all_op)
{
	if (all_op.ra == 0 || all_op.rb == 0)
		return (all_op);
	if (all_op.ra >= all_op.rb)
	{
		all_op.ra = all_op.ra - all_op.rb;
		all_op.rr = all_op.rb;
		all_op.rb = 0;
	}
	else
	{
		all_op.rb = all_op.rb - all_op.ra;
		all_op.rr = all_op.ra;
		all_op.ra = 0;
	}
	return (all_op);
}

t_op	ft_opti_rrotate(t_op all_op)
{
	if (all_op.rra == 0 || all_op.rrb == 0)
		return (all_op);
	if (all_op.rra >= all_op.rrb)
	{
		all_op.rra = all_op.rra - all_op.rrb;
		all_op.rrr = all_op.rrb;
		all_op.rrb = 0;
	}
	else
	{
		all_op.rrb = all_op.rrb - all_op.rra;
		all_op.rrr = all_op.rra;
		all_op.rra = 0;
	}
	return (all_op);
}

t_op	ft_opti_operations(t_op all_op, t_data *data)
{
	int		size_a;
	int		size_b;
	t_op	opt;

	opt = all_op;
	size_a = ft_lstsize(data->stack_a);
	size_b = ft_lstsize(data->stack_b);
	if (size_a > 0 && opt.ra > size_a / 2)
	{
		opt.rra = size_a - opt.ra;
		opt.ra = 0;
	}
	if (size_b > 0 && opt.rb > size_b / 2)
	{
		opt.rrb = size_b - opt.rb;
		opt.rb = 0;
	}
	opt = ft_opti_rotate(opt);
	opt = ft_opti_rrotate(opt);
	return (opt);
}

int	ft_get_all_op(t_op *all_op)
{
	return (all_op->ra + all_op->rb + all_op->rr
		+ all_op->rra + all_op->rrb + all_op->rrr);
}

void	ft_start_operation(t_op *all_op, t_data *data, char type_stack)
{
	while (all_op->ra--)
		ra(data, 1);
	while (all_op->rb--)
		rb(data, 1);
	while (all_op->rr--)
		rr(data, 1);
	while (all_op->rra--)
		rra(data, 1);
	while (all_op->rrb--)
		rrb(data, 1);
	while (all_op->rrr--)
		rrr(data, 1);
	*all_op = (t_op){0, 0, 0, 0, 0, 0};
	if (type_stack == 'a')
		pb(data, 1);
	else
		pa(data, 1);
}
