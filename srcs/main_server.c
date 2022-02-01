/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:20:26 by nargouse          #+#    #+#             */
/*   Updated: 2022/02/01 19:13:38 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	*g_buffer;

static	char *malloc_tab(char *str)
{
	g_buffer = (int*)(malloc(sizeof(int) * 8));
	if (g_buffer == NULL)
	{
		free(g_buffer);
		ft_quit("Malloc allocation error\n");
	}
	str = (char *)malloc(sizeof(char) * BUFF_SIZE);
	if (str == NULL)
	{
		free(str);
		ft_quit("Malloc allocation error\n");
	}
	ft_bzero(g_buffer, 8);
	return (str);
}

static char	*ft_decode_signals(char *str, int *tmp)
{
	tmp = NULL;
	str = NULL;

	ft_printf("%d\n", g_buffer);
	return (str);
}

static void	signal_handler(int sig)
{
	*g_buffer++ = sig;
}

int	main(void)
{
	int		i;
	int		*tmp;
	char	*str;

    ft_printf("%d\n", getpid());
	i = 0;
	str = NULL;
	str = malloc_tab(str);
	tmp = g_buffer;
	signal(SIGUSR1, &signal_handler);
	signal(SIGUSR2, &signal_handler);
	while (1)
	{
		ft_printf("noot bv bvvmbvcbnc\n");
		if (i == 8)
		{
			ft_printf("noot\n");
			str = ft_decode_signals(str, tmp);
			i = 0;
		}
		pause();
		i++;
	}
	return (0);
}
