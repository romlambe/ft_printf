/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:41:51 by romlambe          #+#    #+#             */
/*   Updated: 2023/10/18 22:23:33 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		l;
	va_list	argptr;

	i = 0;
	l = 0;
	va_start(argptr, str);
	while (str[i])
	{
		while (str[i] != '%' && str[i])
		{
			ft_putchar(str[i]);
			i++;
			l++;
		}
		if (str[i])
		{
			i++;
			l += ft_condition(str[i], argptr, l);
			i++;
		}
	}
	return (l);
}

int	ft_condition(char c, va_list argptr, int l)
{
	if (c == 'c')
		return (ft_putchar(va_arg(argptr, int)));
	if (c == 's')
		return (ft_putstr(va_arg(argptr, char *)));
	if (c == 'p')
		return (ft_adress(va_arg(argptr, void *), "0123456789abcedf"));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(argptr, int)));
	if (c == 'x')
		return (ft_putnbr_hexa(va_arg(argptr, unsigned int),
				"0123456789abcdef"));
	if (c == 'X')
		return (ft_putnbr_hexa(va_arg(argptr, unsigned int),
				"0123456789ABCDEF"));
	if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(argptr, unsigned int), "0123456789"));
	if (c == '%')
		return (ft_putchar('%'));
	return (l);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}
/*#include <limits.h>
#include <stdio.h>
int main()
{
	char c = '0';
	char *str = "salut";
	int age = 16;
	int *ptrsurage = &age;
	int uns = 16;
	ft_printf("%c\n%s\n%p\n%d\n%x\n\n", c, str, ptrsurage, age, uns);
	printf("%c\n%s\n%p\n%d\n%x\n", c, str, ptrsurage, age, uns);
}*/
