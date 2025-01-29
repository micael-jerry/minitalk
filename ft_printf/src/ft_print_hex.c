/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:37:55 by mfidimal          #+#    #+#             */
/*   Updated: 2024/03/28 15:37:36 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_write_base_16_nb(unsigned int nbr, char *base, unsigned int size,
		int *len)
{
	char	a;

	if (nbr >= size)
		ft_write_base_16_nb(nbr / size, base, size, len);
	a = base[nbr % size];
	ft_putchar_fd(a, 1);
	*len = *len + 1;
}

static int	ft_putnbr_base_16(unsigned int nbr, int is_upper)
{
	char	*base;
	int		len;

	len = 0;
	if (is_upper)
		base = ft_strdup("0123456789ABCDEF");
	else
		base = ft_strdup("0123456789abcdef");
	ft_write_base_16_nb(nbr, base, 16, &len);
	free(base);
	return (len);
}

int	ft_print_hex_lower(unsigned int n)
{
	int	size;

	size = 0;
	size += ft_putnbr_base_16(n, 0);
	return (size);
}

int	ft_print_hex_upper(unsigned int n)
{
	int	size;

	size = 0;
	size += ft_putnbr_base_16(n, 1);
	return (size);
}
