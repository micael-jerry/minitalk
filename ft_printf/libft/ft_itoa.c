/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:01:01 by mfidimal          #+#    #+#             */
/*   Updated: 2024/02/29 15:09:04 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(int n)
{
	size_t	len;

	if (n < 0)
		n = n * -1;
	len = 1;
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static t_ft_itoa_int_info	get_info(int n)
{
	t_ft_itoa_int_info	info;

	info.intlen = ft_intlen(n);
	if (n < 0)
	{
		info.is_positive = 0;
		info.absolute_value = n * -1;
	}
	else
	{
		info.is_positive = 1;
		info.absolute_value = n;
	}
	return (info);
}

static void	ft_itoa_operation(t_ft_itoa_int_info info, size_t len, char *result)
{
	int	i;

	result[len] = '\0';
	if (!info.is_positive)
		result[0] = '-';
	i = len - 1;
	while (info.absolute_value > 9)
	{
		result[i] = info.absolute_value % 10 + '0';
		info.absolute_value = info.absolute_value / 10;
		i--;
	}
	result[i] = info.absolute_value + '0';
}

char	*ft_itoa(int n)
{
	t_ft_itoa_int_info	info;
	size_t				len;
	char				*result;

	if (n == INT_MIN_VALUE)
		return (ft_strdup("-2147483648"));
	info = get_info(n);
	len = info.intlen + !info.is_positive;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	ft_itoa_operation(info, len, result);
	return (result);
}
