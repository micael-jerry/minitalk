/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:23:35 by mfidimal          #+#    #+#             */
/*   Updated: 2025/02/01 10:16:58 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	is_last_char(char c)
{
	if (c == '\0')
		return (1);
	return (0);
}

static char	*alloc_concat_msg(char *str, int last_index, char c)
{
	char	*alloc;
	int		i;

	alloc = malloc(sizeof(char) * (last_index + 2));
	if (!alloc)
		return (NULL);
	i = 0;
	if (str)
	{
		while (str[i])
		{
			alloc[i] = str[i];
			i++;
		}
		alloc[i] = c;
		i++;
		alloc[i] = '\0';
		free(str);
	}
	else
	{
		alloc[0] = c;
		alloc[1] = '\0';
	}
	return (alloc);
}

void	sig_handler(int sig_num)
{
	static char	bits_char[9];
	static int	bit_index = 0;
	static char	*str = NULL;
	static int	last_i_str = 0;
	char		character;

	if (sig_num == SIGUSR1)
		bits_char[bit_index++] = '0';
	else if (sig_num == SIGUSR2)
		bits_char[bit_index++] = '1';
	else
		put_error("Error: Bad signal received.");
	if (bit_index == 8)
	{
		bits_char[8] = '\0';
		character = binary_to_char(bits_char);
		if (is_last_char(character))
		{
			str = (ft_putendl_fd(str, 1), free(str), NULL);
			last_i_str = 0;
		}
		else
			str = alloc_concat_msg(str, last_i_str++, character);
		bit_index = 0;
	}
}
