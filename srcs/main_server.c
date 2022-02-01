/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:20:26 by nargouse          #+#    #+#             */
/*   Updated: 2022/02/01 20:15:13 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	g_buffer[8];

static void	ft_decode_signals()
{
	;
}

static void	signal_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_printf("1");
	}
	else
	{
		ft_printf("0");
	}
	ft_printf("\n");
}

int	main(void)
{
	int		i;

    ft_printf("%d\n", getpid());
	i = 0;
	signal(SIGUSR1, &signal_handler);
	signal(SIGUSR2, &signal_handler);
	while (1)
	{
		if (i == 8)
		{
			ft_decode_signals();
			i = 0;
		}
		pause();
		i++;
	}
	return (0);
}
