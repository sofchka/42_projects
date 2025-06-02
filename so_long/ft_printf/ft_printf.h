/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:32:34 by szakarya          #+#    #+#             */
/*   Updated: 2025/02/09 20:56:55 by szakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putnbr_base(unsigned long long n, char *base);
int	ft_printf(const char *str, ...);
int	ft_printchar(char a);
int	ft_putstr(const char *str);
int	ft_printnum(long long num);
int	ft_print_ptr(unsigned long long ptr);
int	ft_argument(char c, va_list arg);

#endif
