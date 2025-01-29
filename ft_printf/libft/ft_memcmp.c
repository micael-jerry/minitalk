/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:06:39 by mfidimal          #+#    #+#             */
/*   Updated: 2024/02/23 19:22:33 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*s1_trans;
	char	*s2_trans;

	if (n == 0)
		return (0);
	i = 0;
	s1_trans = (char *)s1;
	s2_trans = (char *)s2;
	while (s1_trans[i] == s2_trans[i])
	{
		if (i == (n - 1))
			return (0);
		i++;
	}
	return ((unsigned char)s1_trans[i] - (unsigned char)s2_trans[i]);
}
