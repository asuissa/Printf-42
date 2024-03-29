/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 11:29:26 by asuissa           #+#    #+#             */
/*   Updated: 2018/02/15 11:29:35 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/*
** 				Initialise g_buf avec des \0
*/

void				pf_ft_bufset(void)
{
	int				n;

	n = 0;
	while (n < 4096)
	{
		g_buf[n] = '\0';
		n++;
	}
	g_i = 0;
}

/*
** 				Affiche g_buf jusqu'à g_i
*/

void				pf_ft_display(t_flag *f)
{
	f->ret += write(1, g_buf, g_i);
	pf_ft_bufset();
}

/*
** 				Affiche (null)
*/

void				pf_ft_buf_null(t_flag *f)
{
	static char		str[6] = "(null)";
	int				i;

	i = 0;
	while (str[i] != '\0')
	{
		pf_ft_buf(str[i], f);
		i++;
	}
}

/*
** 			Ajoute dans g_buf jusqu'à 4095 char et affiche si full
*/

void				pf_ft_buf(char c, t_flag *f)
{
	g_buf[g_i] = c;
	g_i++;
	if (g_i == 4096)
		pf_ft_display(f);
}
