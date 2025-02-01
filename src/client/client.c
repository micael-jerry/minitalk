/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 08:31:44 by mfidimal          #+#    #+#             */
/*   Updated: 2025/02/01 09:47:20 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void send_one_signal(int pid, int sig_val)
{
	int response;

	response = kill(pid, sig_val);

	if (response == -1)
	{
		ft_putendl_fd("Error while sending signal (invalid PID, ...)", 2);
		exit(1);
	}
}

static void	send_signal(int pid, char *msg)
{
	int	i;
	int	j;

	i = 0;
	while (msg[i])
	{
		j = 0;
		while (j < 8)
		{
			if (msg[i] >> (7 - j) & 1)
				send_one_signal(pid, SIGUSR2);
			else
				send_one_signal(pid, SIGUSR1);
			usleep(500);
			j++;
		}
		i++;
	}
	j = 0;
	while (j < 8)
	{
		kill(pid, SIGUSR1);
		usleep(500);
		j++;
	}
}

int	main(int argc, const char *argv[])
{
	int	pid;

	if (argc != 3)
		return (ft_putendl_fd("Invalid Args", 2), 1);
	pid = ft_atoi((char *)argv[1]);
	if (pid <= 0)
		return (ft_putendl_fd("Invalid PID", 2), 1);
	if (!argv[2][0])
		return (ft_putendl_fd("Empty message", 2), 1);
	send_signal(pid, (char *)argv[2]);
	return (0);
}
