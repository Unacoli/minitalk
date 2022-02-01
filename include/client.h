/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:21:04 by nargouse          #+#    #+#             */
/*   Updated: 2022/02/01 16:01:50 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

#include "../libft/include/libft.h"
#include "../libft/include/ft_printf.h"
#include <stdio.h>
#include <signal.h>

int	*ft_dec_to_bin(int n);
int	ft_bin_to_dec(int *n);

void	ft_quit(char *message);

#endif
