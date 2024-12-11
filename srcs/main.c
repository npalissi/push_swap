/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 22:12:15 by edubois-          #+#    #+#             */
/*   Updated: 2024/12/10 20:00:02 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_lst(t_list *a)
{
	while (a)
	{
		ft_printf(1, "%d\n", a->content);
		a = a->next;
	}
}

int	main(int ac, char **av)
{
	t_list	*a;

	if (ac != 1)
	{
		a = NULL;
		av++;
		if (!ft_strlen(*av))
			clean_exit(a, 1);
		check_args(ac, av);
		while (--ac)
			get_stack(*av++, &a);
		check_for_dups(a);
		start_sort(a);
	}
}
