/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 08:31:37 by mfidimal          #+#    #+#             */
/*   Updated: 2025/01/31 15:05:27 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"

int main(void)
{
	int pid = getpid();
	ft_printf("server pid: %d \n", pid);

	if (signal(SIGUSR1, sig_handler)==SIG_ERR)
	{
		exit(0);
	}

	if (signal(SIGUSR2, sig_handler)==SIG_ERR)
	{
		exit(0);
	}

	while (1 == 1)
	{
	}

	return (0);
}
