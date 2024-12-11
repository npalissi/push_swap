/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function_shared.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:17:28 by npalissi          #+#    #+#             */
/*   Updated: 2024/12/11 12:31:02 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrr(t_data *data, int send_message)
{
	rrba(&data->stack_b);
	rrba(&data->stack_a);
	if (send_message)
		write(1, "rrr\n", 4);
}

void	rr(t_data *data, int send_message)
{
	rba(&data->stack_a);
	rba(&data->stack_b);
	if (send_message)
		write(1, "rr\n", 3);
}

void	ss(t_data *data, int send_message)
{
	sba(&data->stack_a);
	sba(&data->stack_b);
	if (send_message)
		write(1, "ss\n", 3);
}
