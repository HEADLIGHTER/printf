/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 17:36:10 by bbellatr          #+#    #+#             */
/*   Updated: 2021/07/14 14:31:35 by bbellatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	write_char(char c, size_t *count)
{
	write(1, &c, 1);
	*count += 1;
}

static int	hexpeps(char c, va_list args, size_t *count)
{
	if (c == '%')
	{
		*count += 1;
		write(1, "%", 1);
	}
	else if (c == 'x' || c == 'X')
	{
		if (c == 'x')
			dtohex(va_arg(args, unsigned int), "0123456789abcdef", count);
		else if (c == 'X')
			dtohex(va_arg(args, unsigned int), "0123456789ABCDEF", count);
	}
	else if (c == 'p')
		pout(va_arg(args, void *), "0123456789abcdef", count);
	if (c == '%' || c == 'x' || c == 'X' || c == 'p')
		return (1);
	return (0);
}

static int	chrstr(char c, va_list args, size_t *count)
{
	char	*strn;

	if (c == 's')
	{
		strn = va_arg(args, char *);
		if (strn == NULL)
		{
			pnull(count);
			return ;
		}
		*count += ft_strlen(strn);
		ft_putstr(strn);
	}
	else if (c == 'c')
	{
		*count += 1;
		ft_putchar_fd(va_arg(args, int), 1);
	}
	if (c == 'c' || c == 's')
		return (1);
	return (0);
}

static int	deinui(char c, va_list args, size_t *count)
{
	char	*strn;

	if (c == 'd' || c == 'i')
	{
		strn = ft_itoa(va_arg(args, int));
		*count += ft_strlen(strn);
		ft_putstr(strn);
		free(strn);
	}
	else if (c == 'u')
	{
		strn = ft_uitoa(va_arg(args, unsigned int));
		*count += ft_strlen(strn);
		ft_putstr(strn);
		free(strn);
	}
	if (c == 'd' || c == 'i' || c == 'u')
		return (1);
	return (0);
}

//say the line JC
int	ft_printf(const char *what_a_shame, ...)
{
	va_list		args;
	size_t		count;

	va_start(args, what_a_shame);
	count = 0;
	while (*what_a_shame && what_a_shame)
	{
		if (*what_a_shame == '%')
		{
			what_a_shame++;
			if (!hexpeps(*what_a_shame, args, &count) && \
					!chrstr(*what_a_shame, args, &count) && \
					!deinui(*what_a_shame, args, &count))
				write_char(*what_a_shame, &count);
		}
		else
			write_char(*what_a_shame, &count);
		if (*what_a_shame)
			what_a_shame++;
	}
	va_end(args);
	free((char *)what_a_shame);
	return (count);
}
