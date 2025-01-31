/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 08:31:44 by mfidimal          #+#    #+#             */
/*   Updated: 2025/01/31 17:41:45 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send_signal(int pid, char *msg)
{
	char *crypted;
	crypted = str_to_binary_str(msg);
	free(crypted);
	kill(pid, SIGUSR1);
}

int main(int argc, const char *argv[])
{
	if (argc != 3)
		ft_printf("Invalid Args\n");
	send_signal(ft_atoi((char *) argv[1]), (char *) argv[2]);
	return (0);
}
