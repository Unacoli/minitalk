/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:20:05 by nargouse          #+#    #+#             */
/*   Updated: 2022/01/29 20:11:35 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void    ft_quit(char *message)
{
    ft_putstr_fd(message, STDERR_FILENO);
    exit(EXIT_FAILURE);
}

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

void    send_signal(char **av)
{
    int i;
    int j;
    int max_bits;

    i = 0;
    max_bits = get_max_bits(av[2]);
    while (i < max_bits)
    {
        j = 0;
        while (j++ < ft_strlen(av[2]) - 1)
        {
            if (((*av[2] >> i) & 1) == 1)
                kill(ft_atoi(av[1]), SIGUSR1);
            else
                kill(ft_atoi(av[1]), SIGUSR2);
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
        send_signal(av);
		return (EXIT_SUCCESS);
	}
	else
		ft_quit("Usage: ./client <PID> <STRING>\n");
	(void)av;
}
