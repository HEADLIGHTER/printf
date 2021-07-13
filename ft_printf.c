/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 17:36:10 by bbellatr          #+#    #+#             */
/*   Updated: 2021/07/12 16:03:18 by bbellatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

static void	write_char(char ch, size_t *c)
{
	write(1, &c, 1);
	*c += 1;
}

static int	hexpeps(char ch, va_list args, size_t *c)
{
	if (c == '%')
	{
		*c += 1;
		write(1, '%', 1);
	}
	else if (c == 'x' || c == 'X')
	{
		if (c == 'x')
			dtohex(va_arg(args, unsigned int), "0123456789abcdef", c);
		else if (c == 'X')
			dtohex(va_arg(args, unsigned int), "0123456789ABCDEF", c);
	}
	else if (c == 'p')
		pout(va_arg(args, void *), "0123456789abcdef", c);
	if (c == '%' || c == 'x' || c == 'X' || c == 'p')
		return (1);
	return (0);
}

static int	chrstr(char ch, va_list args, size_t *c)
{
	char *strn;

	if (c == 's')
	{
		strn = va_arg(args, char *);
		if (strn == NULL)
	}
}

int	ft_printf(const char *say_the_line_JC, ...)
{
	const char	*what_a_shame;
	va_list		args;
	size_t		c;

	what_a_shame = ft_strdup(say_the_line_JC);
	va_start(args, what_a_shame);
	while (*what_a_shame && what_a_shame)
	{
		if (*what_a_shame == %)
		{
			what_a_shame++;
			if (!hexpeps(*what_a_shame, args, &c) && \
					!chrstr(*what_a_shame, args, &c) && \
					!deinui(*what_a_shame, args, &c))
				write_char(*what_a_shame, &c);
		}
		else
			write_char(*what_a_shame, &c);
		if (*what_a_shame)
			what_a_shame++;
	}
	va_end(args);
	return (c);
}
