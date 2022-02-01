/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:38:53 by nargouse          #+#    #+#             */
/*   Updated: 2022/02/01 17:01:15 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "client.h"

void    ft_quit(char *message)
{
    ft_putstr_fd(message, STDERR_FILENO);
    exit(EXIT_FAILURE);
}

int	ft_bin_to_dec(int *n)
{
	int decimal;
	int i;

	decimal = 0;
	i = 0;
	while (i < 8)
	{
		decimal += n[i] * ft_pow(2, i);
		i++;
	}
	return (decimal);
}
