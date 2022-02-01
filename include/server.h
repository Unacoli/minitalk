/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:22:49 by nargouse          #+#    #+#             */
/*   Updated: 2022/02/01 16:01:26 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# define BUFF_SIZE 1024

#include "../libft/include/libft.h"
#include "../libft/include/ft_printf.h"
#include <unistd.h>
#include <signal.h>

extern int *g_buffer;

void	ft_quit(char *message);

int	*ft_dec_to_bin(int n);
int	ft_bin_to_dec(int *n);

#endif
