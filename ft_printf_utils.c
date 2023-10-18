/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:46:07 by romlambe          #+#    #+#             */
/*   Updated: 2023/10/18 11:15:08 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	return(i);
}

int ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putnbr_hexa(unsigned int n, char *base)
{
	int	i;
	int	j;
	char	tab[8];

	while (n != 0 || j == 0)
	{
		tab[j++] = base[n % 16];
		n /= 16;
	}
	while(j)
		i += ft_putchar(tab[--j]);
	return (i);
}

int	ft_adress(void *ptr, char *base)
{
	int					i;
	int					j;
	unsigned long int	n;
	int					len;
	char				tab[16];

	len = ft_strlen(base);
	if (!ptr)
		return (ft_putstr("(nil)"), 5);
	n = (unsigned long int)ptr;
	j = 0;
	i = 0;
	while (n != 0 || j == 0)
	{
		tab[j++] = base[n % len];
		n /= len;
	}
	if (len == 16)
		i += ft_putstr("0x");
	while (j)
		i += ft_putchar(tab[--j]);
	return (i);
}

int	ft_putnbr(int n)
{
	int		i;
	int		j;
	char	tab[12];

	i = 0;
	j = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11), 11);
	if (n < 0)
	{
		i += ft_putchar('-');
		n = -n;
	}
	while (n != 0 || j == 0)
	{
		tab[j++] = n % 10 + '0';
		n /= 10;
	}
	while (j)
		i += ft_putchar(tab[--j]);
	return (i);
}

int	ft_putnbr_unsigned(unsigned int n, char *base)
{
	int		i;
	int		j;
	char	tab[16];

	j = 0;
	i = 0;
	while (n != 0 || j == 0)
	{
		tab[j++] = base[n % 10];
		n /= 10;
	}
	while (j)
		i += ft_putchar(tab[--j]);
	return (i);
}