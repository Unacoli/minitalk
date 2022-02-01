/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nargouse <nargouse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:15:11 by nargouse          #+#    #+#             */
/*   Updated: 2022/02/01 15:52:24 by nargouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_realloc(char *s, int size)
{
	char		*tmp;

	tmp = (char *)malloc(sizeof(char) * (ft_strlen(s) + size));
	if (tmp == NULL)
		free(tmp);
	ft_strlcpy(tmp, s, ft_strlen(s));
	if (s != NULL)
		free(s);
	return (tmp);
}
