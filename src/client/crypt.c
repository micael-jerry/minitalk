/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crypt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:49:53 by mfidimal          #+#    #+#             */
/*   Updated: 2025/01/31 17:40:33 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char *char_to_binary_str(unsigned char c)
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

char *str_to_binary_str(char *str)
{
	char *res;
	int i;
	char *tmp;
	char *joined;

	res = ft_strdup("");
	i = 0;
	while (str[i])
	{
		tmp = char_to_binary_str(str[i]);
		joined = ft_strjoin(res, tmp);
		free(res);
		free(tmp);
		res = joined;
		i++;
	}
	return (res);
}
