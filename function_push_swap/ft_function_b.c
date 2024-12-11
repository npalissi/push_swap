/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:33:06 by npalissi          #+#    #+#             */
/*   Updated: 2024/12/11 12:30:24 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sb(t_data *data, int send_message)
{
	if (!sba(&data->stack_b))
		return (0);
	if (send_message)
		write(1, "sb\n", 3);
	return (1);
}

int	rb(t_data *data, int send_message)
{
	if (!rba(&data->stack_b))
		return (0);
	if (send_message)
		write(1, "rb\n", 3);
	return (1);
}

int	rrb(t_data *data, int send_message)
{
	if (!rrba(&data->stack_b))
		return (0);
	if (send_message)
		write(1, "rrb\n", 4);
	return (1);
}

int	pb(t_data *data, int send_message)
{
	pba(&data->stack_a, &data->stack_b);
	if (send_message)
		write(1, "pb\n", 3);
	return (1);
}
