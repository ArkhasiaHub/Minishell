/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:13:07 by sbriche           #+#    #+#             */
/*   Updated: 2023/12/20 11:38:36 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_get_format(va_list ap, char c, int *count);

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		count;

	if (!s)
		return (0);
	va_start(ap, s);
	count = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] == '%')
		{
			i++;
			ft_get_format(ap, s[i], &count);
		}
		else
			ft_verif_write_c(&count, s[i]);
		if (count == -1)
			break ;
	}
	va_end(ap);
	return (count);
}

static void	ft_get_format(va_list ap, char c, int *count)
{
	if (c == 'c')
		ft_verif_write_c(count, va_arg(ap, int));
	else if (c == 's')
		ft_verif_write_str(count, va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		ft_putnbr_base(va_arg(ap, int), LEN_BASE10, BASE10, count);
	else if (c == 'p')
		ft_verif_ptr(va_arg(ap, unsigned long int), BASE16_LOWER, count);
	else if (c == 'u')
		ft_putnbr_unsigned(va_arg(ap, unsigned int), BASE10, count);
	else if (c == 'x')
		ft_putnbr_hexa(va_arg(ap, unsigned int), BASE16_LOWER, count);
	else if (c == 'X')
		ft_putnbr_hexa(va_arg(ap, unsigned int), BASE16_UPPER, count);
	else if (c == '%')
		ft_verif_write_c(count, '%');
}
