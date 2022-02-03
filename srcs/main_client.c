/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:20:05 by nargouse          #+#    #+#             */
/*   Updated: 2022/02/04 00:53:03 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	kill_wrap(pid_t pid, int sig)
{
	if (kill(pid, sig) == -1)
		ft_quit("Failed to send signal, maybe wrong PID.\n");
}

static void	send_signals(char **av)
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
                kill_wrap(ft_atoi(av[1]), SIGUSR1);
            else
                kill_wrap(ft_atoi(av[1]), SIGUSR2);
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
