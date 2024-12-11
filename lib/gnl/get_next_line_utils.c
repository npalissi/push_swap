/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 06:39:55 by edubois-          #+#    #+#             */
/*   Updated: 2024/12/11 16:34:40 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (s1 && *s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 == '\0');
}

int	ft_strllen(char *s)
{
	int	c;

	c = 0;
	if (!s)
		return (0);
	while (*s++)
		c++;
	return (c);
}

void	*ft_memsett(void *s, int c, size_t n)
{
	void	*clone;

	if (!s)
		return (NULL);
	clone = s;
	while (n--)
		*(unsigned char *)s++ = c;
	return (clone);
}

char	*ft_char_strjoin(char *s1, char *s2)
{
	char	*str;
	char	*save_str;
	char	*s1_tmp;

	s1_tmp = s1;
	str = malloc (ft_strllen(s1) + ft_strllen(s2) + 1);
	if (!str)
		return (NULL);
	save_str = str;
	while (s1 && *s1)
		*str++ = *s1++;
	while (s2 && *s2)
		*str++ = *s2++;
	*str = '\0';
	if (s1_tmp)
		free(s1_tmp);
	return (save_str);
}
