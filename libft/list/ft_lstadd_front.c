/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:13:20 by sbriche           #+#    #+#             */
/*   Updated: 2023/12/20 11:39:16 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/list.h"

void	ft_lstadd_front(t_list **lst, t_list *n)
{
	if (n == NULL)
		return ;
	n->next = *lst;
	*lst = n;
}
