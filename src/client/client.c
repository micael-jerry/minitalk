/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 08:31:44 by mfidimal          #+#    #+#             */
/*   Updated: 2025/02/01 05:21:42 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void send_on_char(int pid, char c)
{
	int j;

	j = 0;
	while (j < 8)
	{
		if (c >> (7 - j) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		j++;
	}
}

void send_signal(int pid, char *msg)
{
	int i;

	i = 0;
	while (msg[i])
	{
		send_on_char(pid, msg[i]);
		i++;
	}
}

int main(int argc, const char *argv[])
{
	int pid;

	if (argc != 3)
		return (ft_printf("Invalid Args\n"), 1);
	pid = ft_atoi((char *) argv[1]);
	if (pid <= 0)
		return (ft_printf("Invalid PID\n"), 1);
	if (!argv[2][0])
		return (ft_printf("Empty message\n"), 1);
	send_signal(pid, (char *) argv[2]);
	return (0);
}
