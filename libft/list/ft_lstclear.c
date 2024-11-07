/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:44:50 by sbriche           #+#    #+#             */
/*   Updated: 2023/12/20 11:39:18 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/list.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (!*lst)
		return ;
	if (!del)
		return ;
	while ((*lst)->next)
	{
		next = (*lst)->next;
		ft_lstdelone(*lst, (*del));
		*lst = next;
	}
	ft_lstdelone(*lst, (*del));
	*lst = NULL;
}
