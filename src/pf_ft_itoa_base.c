/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ft_itoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 11:39:58 by asuissa           #+#    #+#             */
/*   Updated: 2018/02/15 11:40:02 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

uintmax_t		pf_ft_sign(t_flag *f, intmax_t nbr)
{
	f->sign = '+';
	if (nbr < 0)
	{
		f->sign = '-';
		nbr = -nbr;
	}
	return ((uintmax_t)nbr);
}

char			*pf_ft_itoa_base(uintmax_t nbr, int base)
{
	static char	convert[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
	'9', 'A', 'B', 'C', 'D', 'E', 'F'};
	intmax_t	i;
	uintmax_t	n;
	int			converted_nbr[64];
	char		*result;

	if (nbr == 0)
		return ("0");
	i = 0;
	n = (intmax_t)nbr;
	while (n > 0)
	{
		converted_nbr[i++] = n % base;
		n /= base;
	}
	result = (char*)malloc(sizeof(char) * --i);
	result[i + 1] = '\0';
	while (i >= 0)
		result[n++] = convert[converted_nbr[i--]];
	return (result);
}
