/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:44:22 by mfidimal          #+#    #+#             */
/*   Updated: 2024/02/28 19:03:05 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t size)
{
	char	*pointer_temp;
	size_t	i;

	pointer_temp = (char *)pointer;
	i = 0;
	while (i < size)
	{
		pointer_temp[i] = (char)value;
		i++;
	}
	return (pointer);
}
