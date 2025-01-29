/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 06:52:44 by mfidimal          #+#    #+#             */
/*   Updated: 2024/02/25 19:34:40 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	char	*dest_trans;
	char	*src_trans;
	int		i;

	if (dest == src || size == 0)
		return (dest);
	dest_trans = (char *)dest;
	src_trans = (char *)src;
	if (dest_trans > src_trans && (dest_trans - src_trans) < (int)size)
	{
		i = size - 1;
		while (i >= 0)
		{
			dest_trans[i] = src_trans[i];
			i--;
		}
	}
	else
	{
		ft_memcpy(dest, src, size);
	}
	return (dest);
}
