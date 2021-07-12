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



int	ft_printf(const char *say_the_line_JC)
{
	const char	*what_a_shame;
	va_arg	args;

	what_a_shame = ft_strdup(say_the_line_JC);
	va_start(args, what_a_shame);
}
