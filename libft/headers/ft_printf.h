/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrade <dfrade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:04:10 by dfrade            #+#    #+#             */
/*   Updated: 2023/09/09 17:27:23 by dfrade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# define DEC "0123456789"
# define HEX_LW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"

int	ft_printf(const char *format, ...);
int	ft_format_handler(va_list args, char format);
int	ft_strlen(char *str);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putptr(unsigned long nb, char *base);
int	ft_putnbr_base(long int nb, char *base);

#endif