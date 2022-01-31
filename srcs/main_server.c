/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:20:26 by nargouse          #+#    #+#             */
/*   Updated: 2022/01/31 23:15:00 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	*g_buffer;

void	signal_handler(int sig)
{
	 ft_printf("%d\n", sig);
}

int	main(void)
{
    ft_printf("%d\n", getpid());
	signal(SIGUSR1, &signal_handler);
	signal(SIGUSR2, &signal_handler);
	while (1)
	{
		
	}
	return (0);
}
