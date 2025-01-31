/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:23:35 by mfidimal          #+#    #+#             */
/*   Updated: 2025/01/31 15:32:31 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void sig_handler(int sig_num)
{
	if (sig_num == SIGUSR1)
		ft_printf("SIGUSR1\n");
	else if (sig_num == SIGUSR2)
		ft_printf("SIGUSR2\n");
	else
		put_error("Bad signal");
}
