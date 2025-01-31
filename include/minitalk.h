/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:49:58 by mfidimal          #+#    #+#             */
/*   Updated: 2025/01/31 16:28:52 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#define MINITALK_H

#include "../ft_printf/include/ft_printf.h"
#include <sys/types.h>
#include <signal.h>

// client
char	*char_to_binary(unsigned char c);

// server
void	sig_handler(int sig_num);

void	put_error(char *err);

#endif
