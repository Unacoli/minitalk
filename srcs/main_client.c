/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:20:05 by nargouse          #+#    #+#             */
/*   Updated: 2022/02/01 20:22:14 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int get_max_bits(char *av)
{
    int max;
    int max_bits;

    max = ft_strlen(av) - 1;
    max_bits = 0;
    while ((max >> max_bits) != 0)
        max_bits++;
    return (max_bits);
}

void    send_signals(char **av)
{
    int i;
    int j;

    i = 0;
    while (i < ft_strlen(av[2]))
    {
        j = 7;
        while (j >= 0)
        {
            if (((av[2][i] >> j) & 1) == 1)
			{
				ft_printf("1");	
                kill(ft_atoi(av[1]), SIGUSR1);
			}
            else
			{
				ft_printf("0");
                kill(ft_atoi(av[1]), SIGUSR2);
			}
			sleep(1);
			j--;
        }
		ft_printf(" ");
        i++;
    }
	ft_printf("\n");
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
