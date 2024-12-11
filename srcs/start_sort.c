/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:54:45 by edubois-          #+#    #+#             */
/*   Updated: 2024/12/11 16:29:44 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_sort(t_list *lst)
{
	t_list	*save_lst;

	save_lst = lst;
	while (save_lst->next && save_lst->next->content > save_lst->content)
		save_lst = save_lst->next;
	if (!save_lst->next)
		clean_exit(lst, 0);
}

void	start_sort(t_list *lst)
{
	t_data	data;

	data.stack_a = lst;
	data.stack_b = 0;
	check_sort(lst);
	if (ft_lstsize(data.stack_a) <= 3)
		ft_quicksort(&data);
	else if (ft_lstsize(data.stack_a) == 4)
		ft_quicksort_four(&data);
	else if (ft_lstsize(data.stack_a) == 5)
		ft_quisort_five(&data);
	check_sort(data.stack_a);
	ft_turkish_sort(&data);
	ft_clearlst(data.stack_a);
}
