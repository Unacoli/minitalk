/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 13:17:41 by nargouse          #+#    #+#             */
/*   Updated: 2022/01/28 17:29:32 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_if(int s)
{
	if (s > 0)
		return (-1);
	else
		return (0);
}

long	ft_atoi(const char *str)
{
	long	n;
	int		s;
	int		i;

	n = 0;
	i = 0;
	while ((str[i] == ' ' || str[i] == '\n' || str[i] == '\r' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\f') && str[i] != '\0')
		i++;
	s = 1;
	if (str[i] == '-')
	{
		s = -1;
		i++;
	}
	while (str[i])
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	if (n > LONG_MAX)
		return (ft_if(s);
	return (n * s);
}
