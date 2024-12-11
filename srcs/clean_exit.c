/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:58:32 by edubois-          #+#    #+#             */
/*   Updated: 2024/12/11 14:49:36 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_clearlst(t_list *a)
{
	t_list	*save;

	while (a)
	{
		save = a->next;
		free(a);
		a = save;
	}
}

void	clean_exit(t_list *a, int error)
{
	if (a)
		ft_clearlst(a);
	if (error)
		ft_printf(2, "Error \n");
	exit(error != 0);
}
