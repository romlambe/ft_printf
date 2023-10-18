/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:39:28 by romlambe          #+#    #+#             */
/*   Updated: 2023/10/18 11:13:56 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr_hexa(unsigned int n, char *base);
int ft_strlen(char *str);
int	ft_putnbr(int n);
int	ft_adress(void *ptr, char *base);
int ft_putnbr_unsigned(unsigned int n, char *base);


int	ft_condition(char c, va_list argptr, int l);

#endif

