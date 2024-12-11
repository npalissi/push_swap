/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:00:07 by edubois-          #+#    #+#             */
/*   Updated: 2024/12/11 16:32:07 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_sort_bonus(t_data *data)
{
	t_list	*save_lst;

	save_lst = data->stack_a;
	while (save_lst->next && save_lst->next->content > save_lst->content)
		save_lst = save_lst->next;
	if (!save_lst->next && !ft_lstsize(data->stack_b))
		clean_exit_bonus(data->stack_a, 0);
}

int	make_moov(t_data *data, char *s)
{
	if (ft_strcmp("sa\n", s))
		sa(data, 0);
	else if (ft_strcmp("sb\n", s))
		sb(data, 0);
	else if (ft_strcmp("pa\n", s))
		pa(data, 0);
	else if (ft_strcmp("pb\n", s))
		pb(data, 0);
	else if (ft_strcmp("ra\n", s))
		ra(data, 0);
	else if (ft_strcmp("rb\n", s))
		rb(data, 0);
	else if (ft_strcmp("rr\n", s))
		rr(data, 0);
	else if (ft_strcmp("rrr\n", s))
		rrr(data, 0);
	else if (ft_strcmp("rra\n", s))
		rra(data, 0);
	else if (ft_strcmp("rrb\n", s))
		rrb(data, 0);
	else
		return (0);
	return (1);
}

void	start_checker(t_list *lst)
{
	t_data	data;
	char	*s;

	data.stack_a = lst;
	data.stack_b = 0;
	s = get_next_line(0);
	while (s)
	{
		if (!make_moov(&data, s))
			break ;
		free(s);
		s = get_next_line(0);
	}
	free(s);
	check_sort_bonus(&data);
	clean_exit_bonus(data.stack_a, 1);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_data	data;

	data.stack_a = 0;
	data.stack_b = 0;
	if (ac != 1)
	{
		a = NULL;
		av++;
		check_args(ac, av);
		while (--ac)
			get_stack(*av++, &a);
		data.stack_a = a;
		check_for_dups(a);
		check_sort_bonus(&data);
		start_checker(a);
	}
}
