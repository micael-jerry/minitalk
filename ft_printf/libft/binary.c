/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 09:50:27 by mfidimal          #+#    #+#             */
/*   Updated: 2025/02/01 09:51:36 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*char_to_binary_str(unsigned char c)
{
	char	*res;
	int		i;

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

char	*str_to_binary_str(char *str)
{
	char	*res;
	int		i;
	char	*tmp;
	char	*joined;

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

char	binary_to_char(char *binary)
{
	char	num;
	int		i;

	if (ft_strlen(binary) != 8)
		return (0);
	num = 0;
	i = 0;
	while (i <= 7)
	{
		if (binary[i] == '1')
			num += (1 << (7 - i));
		i++;
	}
	return (num);
}
