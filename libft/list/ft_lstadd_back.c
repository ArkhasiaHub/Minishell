/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:35:37 by sbriche           #+#    #+#             */
/*   Updated: 2023/12/20 11:39:13 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/list.h"

void	ft_lstadd_back(t_list **lst, t_list *n)
{
	t_list	*current;

	if (!*lst)
	{
		*lst = n;
		return ;
	}
	current = *lst;
	while (current->next != NULL)
		current = current->next;
	current->next = n;
}
