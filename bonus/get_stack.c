/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 22:12:24 by edubois-          #+#    #+#             */
/*   Updated: 2024/12/11 16:40:16 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_lennb(char *s)
{
	int	c;
	int	i;

	c = 0;
	i = 0;
	while (s[i] && (ft_isdigit(s[i]) || ft_issign(s[i])))
	{
		i++;
		c++;
	}
	return (c);
}

int	delete_zero(char *s)
{
	if (*s == '0' && ft_isdigit(s[1]))
		return (1);
	return (0);
}

int	get_stack(char *str, t_list **stack)
{
	int		overflow;
	int		nb;

	nb = 0;
	if (!str || ft_strlen(str) == 0)
		clean_exit_bonus(*stack, 2);
	while (str && *str)
	{
		overflow = 0;
		while (*str && (ft_iswhitespace(*str) || delete_zero(str)))
			str++;
		nb = ft_atoi(str, &overflow);
		if (overflow)
			clean_exit_bonus(*stack, 2);
		ft_lstadd_back(stack, ft_lstnew(nb));
		str += ft_lennb(str);
		while (*str && (ft_iswhitespace(*str) || delete_zero(str)))
			str++;
	}
	if (!stack)
		return (0);
	return (1);
}
