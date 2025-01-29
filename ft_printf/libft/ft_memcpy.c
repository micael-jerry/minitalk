/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:43:07 by mfidimal          #+#    #+#             */
/*   Updated: 2024/03/14 18:43:14 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	unsigned char		*result;
	const unsigned char	*source;
	size_t				i;

	result = dest;
	source = src;
	i = 0;
	if (dest == src || !size)
		return (dest);
	while (i < size)
	{
		result[i] = source[i];
		i++;
	}
	return (dest);
}
