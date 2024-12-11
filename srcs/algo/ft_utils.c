/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:32:22 by npalissi          #+#    #+#             */
/*   Updated: 2024/12/10 16:56:00 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_get_pos(t_list *stack, t_list *node)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp == node)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (0);
}

t_list	*ft_get_big(t_list *stack)
{
	t_list	*tmp;
	t_list	*bigger;
	int		found;

	tmp = stack;
	found = INT_MIN;
	while (tmp)
	{
		if (tmp->content > found)
		{
			found = tmp->content;
			bigger = tmp;
		}
		tmp = tmp->next;
	}
	return (bigger);
}

t_list	*ft_get_min(t_list *stack)
{
	t_list	*tmp;
	t_list	*min;

	min = stack;
	tmp = stack->next;
	while (tmp)
	{
		if (tmp->content < min->content)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

t_list	*ft_get_bigger(int content, t_list *stack)
{
	t_list	*tmp;
	t_list	*big;
	int		found;

	tmp = stack;
	found = INT_MAX;
	big = 0;
	while (tmp)
	{
		if (tmp->content > content && tmp->content < found)
		{
			found = tmp->content;
			big = tmp;
		}
		tmp = tmp->next;
	}
	if (!big)
		return (ft_get_min(stack));
	return (big);
}

t_list	*ft_get_smaller(int content, t_list *stack)
{
	t_list	*tmp;
	t_list	*small;
	int		found;

	tmp = stack;
	small = 0;
	found = INT_MIN;
	while (tmp)
	{
		if (tmp->content < content && tmp->content > found)
		{
			found = tmp->content;
			small = tmp;
		}
		tmp = tmp->next;
	}
	if (!small)
		return (ft_get_big(stack));
	return (small);
}
