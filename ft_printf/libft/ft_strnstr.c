/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:09:32 by mfidimal          #+#    #+#             */
/*   Updated: 2024/02/29 12:13:14 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	big_len;
	size_t	little_len;

	little_len = ft_strlen(little);
	big_len = ft_strlen(big);
	if ((little_len == 0 && big_len == 0) || (big_len > 0 && little_len == 0
			&& len == 0))
		return ((char *)&big[0]);
	if (!big || !little || big_len < little_len || len < little_len)
		return (NULL);
	i = 0;
	while ((i + little_len) <= len)
	{
		if (ft_strncmp(&big[i], little, little_len) == 0)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
