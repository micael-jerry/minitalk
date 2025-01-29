/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:52:41 by mfidimal          #+#    #+#             */
/*   Updated: 2024/02/25 12:31:37 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(const char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static t_str_trim_info	str_trim_result_len(const char *s1, const char *set)
{
	t_str_trim_info	trim_info;

	trim_info.start = 0;
	while (s1[trim_info.start] != '\0')
	{
		if (is_set(s1[trim_info.start], set))
			trim_info.start++;
		else
			break ;
	}
	trim_info.end = ft_strlen(s1);
	while (trim_info.start < trim_info.end)
	{
		if (is_set(s1[trim_info.end - 1], set))
			trim_info.end--;
		else
			break ;
	}
	return (trim_info);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char			*result;
	size_t			i;
	t_str_trim_info	info;

	info = str_trim_result_len(s1, set);
	result = (char *)malloc(sizeof(char) * (info.end - info.start + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (info.start + i < info.end)
	{
		result[i] = s1[info.start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
