/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:46:26 by sbriche           #+#    #+#             */
/*   Updated: 2023/12/20 11:45:18 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/write.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n >= -9 && n <= 9)
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			ft_putchar_fd(-(n) + '0', fd);
		}
		else
			ft_putchar_fd(n + '0', fd);
	}
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			ft_putnbr_fd(-(n / 10), fd);
			ft_putchar_fd(-(n % 10) + '0', fd);
		}
		else if (n >= 10)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putchar_fd(n % 10 + '0', fd);
		}
	}
}
