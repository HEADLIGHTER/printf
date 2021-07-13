/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 23:14:18 by bbellatr          #+#    #+#             */
/*   Updated: 2021/07/13 23:14:18 by bbellatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s)
{
	if (s)
		write(1, s, ft_strlen(s));
}

void	dtohex(unsigned int n, char *base, size_t *count)
{
	unsigned int	i;

	if (n >= 16)
	{
		i = n % 16;
		n = n / 16;
		dtohex(n, base, count);
		write(1, base + i, 1);
		*count += 1;
	}

	else if (n >= 0 && n < 16)
	{
		i = n % 16;
		write(1, base + i, 1);
		*count += 1;
	}
}

void	pnull(size_t *count)
{
	write(1, "(null)", 6);
	*count += 6;
}

void	pout(void *arg, char *base, size_t *count)
{
	size_t	i;
	size_t	sarg;

	sarg = (size_t)arg;
	if (sarg >= 16)
	{
		i = sarg % 16;
		sarg = sarg / 16;
		pout((void *)sarg, base, count);
		write(1, base + i, 1);
		*count += 1;
	}
	else if (sarg >= 0 && sarg < 16)
	{
		i = sarg % 16;
		write(1, "0x", 2);
		write(1, base + i, 1);
		*count += 3;
	}
}
