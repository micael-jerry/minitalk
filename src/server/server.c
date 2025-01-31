/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 08:31:37 by mfidimal          #+#    #+#             */
/*   Updated: 2025/01/31 21:30:57 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"

int main(void)
{
	int pid = getpid();
	ft_printf("server PID: %d \n", pid);

	if (signal(SIGUSR1, sig_handler)==SIG_ERR)
		exit(0);
	if (signal(SIGUSR2, sig_handler)==SIG_ERR)
		exit(0);

	while (1 == 1)
		pause();
	return (0);
}
