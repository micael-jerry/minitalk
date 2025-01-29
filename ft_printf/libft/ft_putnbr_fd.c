/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:37:13 by mfidimal          #+#    #+#             */
/*   Updated: 2024/02/25 12:30:36 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_min_value_fd(int fd)
{
	ft_putstr_fd("-2147483648", fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	nb;

	if (n == INT_MIN_VALUE)
	{
		ft_putnbr_min_value_fd(fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -n;
	}
	else
		nb = n;
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		nb = nb % 10;
	}
	ft_putchar_fd(nb + '0', fd);
}
