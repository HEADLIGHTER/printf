/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 23:54:32 by bbellatr          #+#    #+#             */
/*   Updated: 2021/07/13 23:54:32 by bbellatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	sl(unsigned int n)
{
	int	i;

	i = 0;
	while(n)
	{
		n / 10;
		i++;
	}
	if (i == 0)
		return (1);
	return (i);
}

static int	rec(char **str, unsigned int n)
{
	char	digit;

	if (n >= 10)
	{
		digit = (n % 10) + 48;
		n = n / 10;
		rec(str, n);
		*(*str)++ = digit;
	}
	else if (n >= 0 && n <= 9)
	{
		digit = n + 48;
		*(*str)++ = digit;
	}
}

char	*ft_uitoa(unsigned int n)
{
	char	*str;
	int		strl;

	strl = sl(n);
	str = (char *)ft_calloc(strl + 1, sizeof(*str));
	if (!str)
		return (NULL);
	rec(&str, n);
	return (str - strl);
}
