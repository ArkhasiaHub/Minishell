/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:02:22 by sbriche           #+#    #+#             */
/*   Updated: 2023/12/11 13:55:13 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>

# define BASE10 "0123456789"
# define LEN_BASE10 10
# define BASE16_UPPER "0123456789ABCDEF"
# define BASE16_LOWER "0123456789abcdef"
# define LEN_BASE16 16

int		ft_printf(const char *s, ...);
int		printf_putchar(char c);
int		printf_putstr(char *s);
size_t	printf_strlen(const char *s);
void	ft_putnbr_base(long long nb, int len, char *base, int *count);
void	ft_putnbr_hexa(unsigned long long nb, char *base, int *count);
void	ft_putnbr_unsigned(unsigned int nb, char *base, int *count);
void	ft_putptr(unsigned long int nb, char *base, int *count);
void	ft_verif_ptr(unsigned long int nb, char *base, int *count);
int		ft_verif_write_c(int *count, char c);
int		ft_verif_write_str(int *count, char *str);

#endif
