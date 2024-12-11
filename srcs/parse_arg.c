/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:35:38 by edubois-          #+#    #+#             */
/*   Updated: 2024/12/10 19:16:41 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_for_letters(char **av, int ac)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (--ac && av[++j])
	{
		i = 0;
		while (av[j][i] && ft_strchr(" 0123456789-+", av[j][i]))
			i++;
		if (av[j][i])
			clean_exit(NULL, 1);
	}
	if (av[++j])
		clean_exit(NULL, 1);
}

void	check_for_sign(char **av, int ac)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (--ac && av[++j])
	{
		i = 0;
		while (av[j][i])
		{
			if (ft_issign(av[j][i]) && !ft_isdigit(av[j][i + 1]))
				clean_exit(NULL, 1);
			i++;
		}
	}
	if (av[++j])
		clean_exit(NULL, 1);
}

void	check_for_dups(t_list *lst)
{
	t_list	*save_lst;
	t_list	*keep_lst;

	save_lst = lst;
	keep_lst = lst;
	while (save_lst)
	{
		lst = lst->next;
		while (lst && lst->content != save_lst->content)
		{
			lst = lst->next;
		}
		if (lst)
			clean_exit(keep_lst, 1);
		save_lst = save_lst->next;
		lst = save_lst;
	}
}

void	check_args(int ac, char **av)
{
	check_for_letters(av, ac);
	check_for_sign(av, ac);
}
