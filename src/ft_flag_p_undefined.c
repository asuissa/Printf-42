/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_p_undefined.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 11:32:58 by asuissa           #+#    #+#             */
/*   Updated: 2018/02/15 11:33:06 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/*
**			'p' : Applique le mask, traitement en numb
*/

int		pf_ft_handler_p(t_flag *f, va_list *ap)
{
	static int	mask_p[13] = {0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2};

	f->fla[2] = 1;
	pf_ft_apply_mask(f, mask_p);
	f->arg = pf_ft_strlwr(pf_ft_itoa_base((uintmax_t)va_arg(*ap, void*), 16));
	if (f->fla[0] == -1 && f->arg[0] == '0')
	{
		pf_ft_buf('0', f);
		pf_ft_buf('x', f);
	}
	else
		pf_ft_handler_numb(f);
	return (0);
}

/*
**			'undefined' : Applique le mask, traite en char
*/

int		pf_ft_handler_undefined(t_flag *f)
{
	static int	mask_und[13] = {0, 0, 2, 1, 1, 2, 2, 2, 2, 2, 1, 2, 2};
	char		c[2];

	f->fla[0] = 0;
	if (f->spe == 0)
	{
		f->ret = 0;
		return (f->ret);
	}
	c[0] = f->spe;
	c[1] = '\0';
	f->arg = c;
	pf_ft_apply_mask(f, mask_und);
	return (pf_ft_handler_char(f));
}
