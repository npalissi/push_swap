/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:24:24 by npalissi          #+#    #+#             */
/*   Updated: 2024/12/11 14:05:28 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_min_to_top(t_data *data)
{
	t_list	*min;
	int		pos;
	int		rotate;

	min = ft_get_min(data->stack_a);
	pos = ft_get_pos(data->stack_a, min);
	rotate = pos < ft_lstsize(data->stack_a) / 2;
	while (data->stack_a != min)
	{
		if (rotate)
			ra(data, 1);
		else
			rra(data, 1);
	}
}

void	ft_quicksort_four(t_data *data)
{
	ft_min_to_top(data);
	pb(data, 1);
	ft_quicksort(data);
	pa(data, 1);
}

void	ft_quisort_five(t_data *data)
{
	ft_min_to_top(data);
	pb(data, 1);
	ft_min_to_top(data);
	pb(data, 1);
	ft_quicksort(data);
	pa(data, 1);
	pa(data, 1);
}
