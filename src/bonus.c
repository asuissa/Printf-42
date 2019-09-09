/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 06:48:54 by asuissa           #+#    #+#             */
/*   Updated: 2018/02/15 09:46:58 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		pf_ft_handler_b(t_flag *f, va_list *ap)
{
	static int	mask_b[13] = {0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2};

	f->fla[2] = 1;
	pf_ft_apply_mask(f, mask_b);
	f->arg = pf_ft_itoa_base(va_arg(*ap, long long), 2);
	pf_ft_handler_bonus(f);
	return (0);
}

int		pf_ft_handler_m(t_flag *f, va_list *ap)
{
	static int	mask_m[13] = {0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2};

	f->fla[2] = 1;
	pf_ft_apply_mask(f, mask_m);
	f->arg = ft_itoa_base(va_arg(*ap, long long), va_arg(*ap, char *));
	pf_ft_handler_bonus(f);
	return (0);
}

int		pf_ft_handler_w(t_flag *f, va_list *ap)
{
	static int	mask_w[13] = {0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2};

	f->fla[2] = 1;
	pf_ft_apply_mask(f, mask_w);
	f->arg = ft_itoa(ft_atoi_base(va_arg(*ap, char *), va_arg(*ap, char *)));
	pf_ft_handler_bonus(f);
	return (0);
}

int		pf_ft_handler_n(t_flag *f, va_list *ap)
{
	int	*n;

	n = va_arg(*ap, int *);
	*n = f->ret + g_i;
	return (0);
}
