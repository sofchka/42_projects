/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:10:32 by szakarya          #+#    #+#             */
/*   Updated: 2025/02/09 20:55:45 by szakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char a)
{
	return (write(1, &a, 1));
}

int	ft_argument(char c, va_list arg)
{
	int	n;

	n = 0;
	if (c == 'c')
		n += ft_printchar(va_arg(arg, int));
	else if (c == 's')
		n += ft_putstr(va_arg(arg, char *));
	else if (c == 'p')
		n += ft_print_ptr(va_arg(arg, unsigned long long));
	else if (c == 'd' || c == 'i')
		n += ft_printnum(va_arg(arg, int));
	else if (c == 'u')
		n += ft_printnum(va_arg(arg, unsigned int));
	else if (c == 'x')
		n += ft_putnbr_base(va_arg(arg, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		n += ft_putnbr_base(va_arg(arg, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		n += ft_printchar('%');
	return (n);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		len;
	int		args;

	va_start(arg, str);
	len = 0;
	args = 0;
	while (str[len])
	{
		if (str[len] == '%' && str[len + 1])
		{
			args += ft_argument(str[len + 1], arg);
			len++;
		}
		else
			args += ft_printchar(str[len]);
		len++;
	}
	va_end(arg);
	return (args);
}
/*
#include <stdio.h>
int main(void)
{
	char *name = "Petros";
	int i = 11;
	int j = -1234567;
	int num = ft_printf("hello world\n cute %s %d:%d\n", name, i, j);
	int num2 = printf("hello world\n cute %s %d:%d\n", name, i, j);
	printf("%d\n", num);
	printf("%d\n", num2);
	return (0);
}*/
