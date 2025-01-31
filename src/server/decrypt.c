/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decrypt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 19:21:14 by mfidimal          #+#    #+#             */
/*   Updated: 2025/01/31 19:26:30 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	binary_to_char(char *binary)
{
	char num;
	int i;

	if (ft_strlen(binary) != 8)
		return (0);
	num = 0;
	i = 0;
	while (i <= 7)
	{
		if (binary[i] == '1')
			num += 	
		i++;
	}
}