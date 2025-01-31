/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crypt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:49:53 by mfidimal          #+#    #+#             */
/*   Updated: 2025/01/31 16:30:24 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char *char_to_binary(unsigned char c)
{
	char *res;
	int i;

	res = ft_strdup("00000000");
	i = 0;
	while (i < 8)
	{
		if (c & (1 << i))
			res[7 - i] = '1';
		i++;
	}
	return (res);
}
