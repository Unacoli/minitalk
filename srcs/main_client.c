/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:20:05 by nargouse          #+#    #+#             */
/*   Updated: 2022/01/29 18:50:49 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void    ft_quit(char *message)
{
    ft_putstr_fd(message, STDERR_FILENO);
    exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
        if (ft_int_error(2, av) == EXIT_FAILURE || ft_atoi(av[1]) < 2)
           ft_quit("Wrong PID or cannot be 1.\n");
		return (EXIT_SUCCESS);
	}
	else
		ft_quit("Usage: ./client <PID> <STRING>\n");
	(void)av;
}
