/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:20:05 by nargouse          #+#    #+#             */
/*   Updated: 2022/02/04 00:32:34 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void    send_signals(char **av)
{
    int i;
    int j;

    i = 0;
    while (i < ft_strlen(av[2]))
    {
        j = 0;
        while (j < 8)
        {
            if (((av[2][i] >> j) & 1) == 1)
                kill(ft_atoi(av[1]), SIGUSR1);
            else
                kill(ft_atoi(av[1]), SIGUSR2);
			usleep(SLEEP_TIME);
			j++;
        }
        i++;
    }
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
        if (ft_int_error(2, av) == EXIT_FAILURE || ft_atoi(av[1]) < 2)
           ft_quit("Wrong PID or cannot be 1.\n");
        send_signals(av);
		return (EXIT_SUCCESS);
	}
	else
		ft_quit("Usage: ./client <PID> <STRING>\n");
	(void)av;
}
