/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:09:30 by szakarya          #+#    #+#             */
/*   Updated: 2025/02/09 21:01:41 by szakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long long n, char *base)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_putnbr_base(n / 16, base);
	count += write(1, &base[n % 16], 1);
	return (count);
}

int	ft_printnum(long long num)
{
	int		count;
	char	c;

	count = 0;
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
		count++;
	}
	if (num >= 10)
		count += ft_printnum(num / 10);
	c = (num % 10) + '0';
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_putstr(const char *str)
{
	int	i;

	if (!str)
		return (write(1, "(null)", 6));
	i = 0;
	while (str[i])
		i += write(1, &str[i], 1);
	return (i);
}

int	ft_print_ptr(unsigned long long ptr)
{
	int		res;

	if (ptr == 0)
		return (ft_putstr("0x0"));
	res = 0;
	res += ft_putstr("0x");
	res += ft_putnbr_base(ptr, "0123456789abcdef");
	return (res);
}
