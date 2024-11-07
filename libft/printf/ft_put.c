/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:03:04 by sbriche           #+#    #+#             */
/*   Updated: 2023/12/20 11:38:39 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_base(long long nb, int len, char *base, int *count)
{
	if (nb < 0)
	{
		if (len != LEN_BASE16)
		{
			if (ft_verif_write_c(count, '-') == -1)
				return ;
		}
		if (nb <= -len)
			ft_putnbr_base(-(nb / len), len, base, count);
		if (ft_verif_write_c(count, base[-(nb % len)]) == -1)
			return ;
	}
	else if (nb < len)
	{
		if (ft_verif_write_c(count, base[nb % len]) == -1)
			return ;
	}
	else
	{
		ft_putnbr_base(nb / len, len, base, count);
		if (ft_verif_write_c(count, base[nb % len]) == -1)
			return ;
	}
}

void	ft_putnbr_hexa(unsigned long long nb, char *base, int *count)
{
	if (nb < LEN_BASE16)
	{
		if (ft_verif_write_c(count, base[nb % LEN_BASE16]) == -1)
			return ;
	}
	else
	{
		ft_putnbr_hexa(nb / LEN_BASE16, base, count);
		if (ft_verif_write_c(count, base[nb % LEN_BASE16]) == -1)
			return ;
	}
}

void	ft_putnbr_unsigned(unsigned int nb, char *base, int *count)
{
	if (nb <= 9)
	{
		if (ft_verif_write_c(count, base[nb % LEN_BASE10]) == -1)
			return ;
	}
	else
	{
		ft_putnbr_unsigned(nb / LEN_BASE10, base, count);
		if (ft_verif_write_c(count, base[nb % LEN_BASE10]) == -1)
			return ;
	}
}

void	ft_putptr(unsigned long int nb, char *base, int *count)
{
	if (nb < LEN_BASE16)
	{
		if (ft_verif_write_c(count, base[nb % LEN_BASE16]) == -1)
			return ;
	}
	else
	{
		ft_putptr(nb / LEN_BASE16, base, count);
		if (ft_verif_write_c(count, base[nb % LEN_BASE16]) == -1)
			return ;
	}
}

void	ft_verif_ptr(unsigned long int nb, char *base, int *count)
{
	if (nb == 0)
	{
		ft_verif_write_str(count, "(nil)");
		return ;
	}
	if (ft_verif_write_str(count, "0x") == -1)
		return ;
	ft_putptr(nb, base, count);
}
