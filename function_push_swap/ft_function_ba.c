/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function_ba.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:37:13 by npalissi          #+#    #+#             */
/*   Updated: 2024/12/11 12:46:57 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rba(t_list **pile)
{
	t_list	*tmp;

	if (ft_lstsize(*pile) == 1)
		return (0);
	tmp = *pile;
	*pile = tmp->next;
	tmp->next = 0;
	ft_lstlast(*pile)->next = tmp;
	return (1);
}

int	sba(t_list **pile)
{
	t_list	*tmp;
	t_list	*first;

	if (ft_lstsize(*pile) <= 1)
		return (0);
	tmp = (*pile)->next->next;
	first = *pile;
	*pile = (*pile)->next;
	(*pile)->next = first;
	if (tmp)
		first->next = tmp;
	else
		first->next = 0;
	return (1);
}

int	rrba(t_list **pile)
{
	t_list	*tmp;
	t_list	*last;

	if (ft_lstsize(*pile) <= 1)
		return (0);
	last = ft_lstlast(*pile);
	if (!last)
		return (0);
	tmp = *pile;
	while (tmp->next != last)
		tmp = tmp->next;
	tmp->next = 0;
	ft_lstadd_front(pile, last);
	return (1);
}

int	pba(t_list **pile_1, t_list **pile_2)
{
	t_list	*tmp;

	if (!*pile_1)
		return (0);
	tmp = *pile_1;
	*pile_1 = (*pile_1)->next;
	if (!pile_1)
		return (0);
	ft_lstadd_front(pile_2, tmp);
	return (1);
}
