/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 08:31:44 by mfidimal          #+#    #+#             */
/*   Updated: 2025/01/31 22:18:15 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send_signal(int pid, char *msg)
{
	char *crypted;
	int i;
	crypted = str_to_binary_str(msg);

	i = 0;
	while (crypted[i])
	{
		if (crypted[i] == '0')
			kill(pid, SIGUSR1);
		else if (crypted[i] == '1')
			kill(pid, SIGUSR2);
		usleep(500);
		i++;
	}
	free(crypted);
}

int main(int argc, const char *argv[])
{
	if (argc != 3)
		ft_printf("Invalid Args\n");
	send_signal(ft_atoi((char *) argv[1]), (char *) argv[2]);
	return (0);
}
