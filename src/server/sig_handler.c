/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:23:35 by mfidimal          #+#    #+#             */
/*   Updated: 2025/01/31 22:09:56 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void sig_handler(int sig_num)
{
    static char bits_char[9];
    static int bit_index;
    static int is_initialized;

    if (!is_initialized)
    {
        bit_index = 0;
        is_initialized = 1;
    }

    if (sig_num == SIGUSR1)
        bits_char[bit_index++] = '0';
    else if (sig_num == SIGUSR2)
        bits_char[bit_index++] = '1';
    else
        put_error("Error: Bad signal received.");

    if (bit_index == 8)
    {
        bits_char[8] = '\0';
        ft_printf("%c", binary_to_char(bits_char));
        bit_index = 0;
    }
}
