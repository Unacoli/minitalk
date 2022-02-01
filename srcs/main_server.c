/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:20:26 by nargouse          #+#    #+#             */
/*   Updated: 2022/02/01 21:08:35 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	g_buffer[9];

static void	ft_reset_buffer()
{
	int	i;
	
	i = 1;
	g_buffer[0] = 1;
	while (i < 9)
		g_buffer[i++] = 42;
}

static void	ft_decode_signals()
{
	int	i;

	i = 1;
	while (i < 9)
	{
		ft_printf("%d\n", g_buffer[i]);
		i++;
	}
}

static void	signal_handler(int sig)
{
	if (sig == SIGUSR1)
		g_buffer[g_buffer[0]] = 1;
	else
		g_buffer[g_buffer[0]] = 0;
	g_buffer[0] = g_buffer[0] + 1;
}

int	main(void)
{
	int		i;

    ft_printf("%d\n", getpid());
	i = 0;
	g_buffer[0] = 1;
	signal(SIGUSR1, &signal_handler);
	signal(SIGUSR2, &signal_handler);
	while (1)
	{
		if (i == 8)
		{
			ft_decode_signals();
			i = 0;
			ft_reset_buffer();
		}
		pause();
		i++;
	}
	return (0);
}
