/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 02:40:19 by npalissi          #+#    #+#             */
/*   Updated: 2024/12/11 12:31:52 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sa(t_data *data, int send_message)
{
	if (!sba(&data->stack_a))
		return (0);
	if (send_message)
		write(1, "sa\n", 3);
	return (1);
}

int	ra(t_data *data, int send_message)
{
	if (!rba(&data->stack_a))
		return (0);
	if (send_message)
		write(1, "ra\n", 3);
	return (1);
}

int	rra(t_data *data, int send_message)
{
	if (!rrba(&data->stack_a))
		return (0);
	if (send_message)
		write(1, "rra\n", 4);
	return (1);
}

int	pa(t_data *data, int send_message)
{
	pba(&data->stack_b, &data->stack_a);
	if (send_message)
		write(1, "pa\n", 3);
	return (1);
}
