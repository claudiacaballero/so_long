/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:04:50 by ccaballe          #+#    #+#             */
/*   Updated: 2023/04/05 16:14:53 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	if (write(1, &c, 1) != 1)
		return (-1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		if (write(1, "(null)", 6) != 6)
			return (-1);
		return (6);
	}
	while (s[i])
	{
		if (ft_putchar(s[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_putptr(unsigned long ptr)
{
	char	*hex;
	int		res;
	int		aux;

	hex = "0123456789abcdef";
	res = 0;
	aux = 0;
	if (ptr > 15)
	{
		aux = ft_putptr(ptr / 16);
		if (aux == -1)
			return (-1);
		res += aux;
	}
	aux = ft_putchar((hex[ptr % 16]));
	if (aux == -1)
		return (-1);
	res += aux;
	return (res);
}

int	ft_putnbr(long long int nb, int c)
{
	if (nb < 0)
	{
		if (ft_putchar('-') != 1)
			return (-1);
		c++;
		nb *= -1;
	}
	if (nb > 9)
		c = ft_putnbr(nb / 10, c);
	if (c == -1)
		return (-1);
	if (write(1, &"0123456789"[nb % 10], 1) != 1)
		return (-1);
	c++;
	return (c);
}

int	ft_putnbr_base(unsigned int nb, char c)
{
	char	*hex;
	int		res;
	int		aux;

	hex = "0123456789abcdef";
	if (c == 'X')
		hex = "0123456789ABCDEF";
	res = 0;
	aux = 0;
	if (nb > 15)
	{
		aux = ft_putnbr_base(nb / 16, c);
		if (aux == -1)
			return (-1);
		res += aux;
	}
	aux = ft_putchar((hex[nb % 16]));
	if (aux == -1)
		return (-1);
	res += aux;
	return (res);
}
