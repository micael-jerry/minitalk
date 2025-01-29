/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:55:43 by mfidimal          #+#    #+#             */
/*   Updated: 2024/03/06 14:41:27 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*actual_last_element;

	if (!lst[0])
	{
		lst[0] = new;
		return ;
	}
	actual_last_element = ft_lstlast(lst[0]);
	actual_last_element->next = new;
}
