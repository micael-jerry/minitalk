/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:51:31 by mfidimal          #+#    #+#             */
/*   Updated: 2024/02/25 12:31:18 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_separator(char chr, char sep)
{
	if (chr == sep || chr == '\0')
		return (1);
	return (0);
}

static size_t	result_size(const char *str, char sep)
{
	size_t	size;
	size_t	i;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (is_separator(str[i], sep) == 0 && is_separator(str[i + 1],
				sep) == 1)
			size++;
		i++;
	}
	return (size);
}

static void	copy(char *dest, const char *src, char sep)
{
	int	i;

	i = 0;
	while (is_separator(src[i], sep) == 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static void	split(char **array, const char *str, char sep)
{
	int	i;
	int	j;
	int	array_index;

	array_index = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (is_separator(str[i], sep) == 1)
			i++;
		else
		{
			j = 0;
			while (is_separator(str[i + j], sep) == 0)
				j++;
			array[array_index] = (char *)malloc(sizeof(char) * (j + 1));
			copy(array[array_index], &str[i], sep);
			i += j;
			array_index++;
		}
	}
}

char	**ft_split(const char *str, char sep)
{
	size_t	size;
	char	**result;

	size = result_size(str, sep);
	result = (char **)malloc(sizeof(char *) * (size + 1));
	if (result == NULL)
		return (NULL);
	split(result, str, sep);
	result[size] = NULL;
	return (result);
}
