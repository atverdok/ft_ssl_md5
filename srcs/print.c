/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 10:24:54 by atverdok          #+#    #+#             */
/*   Updated: 2019/04/10 10:24:59 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void	print_out(const char *str, char *mes_digest, \
					char command, const char *name)
{
	if (command & FLAG_Q)
		ft_putstr(mes_digest);
	else if (command & FLAG_R)
	{
		ft_putstr(mes_digest);
		ft_putchar(' ');
		if (command & FLAG_S)
			ft_putchar('"');
		ft_putstr(str);
		if (command & FLAG_S)
			ft_putchar('"');
	}
	else
	{
		ft_putstr(name);
		write(1, " (", 2);
		if (command & FLAG_S)
			ft_putchar('"');
		ft_putstr(str);
		if (command & FLAG_S)
			ft_putchar('"');
		write(1, ") = ", 4);
		ft_putstr(mes_digest);
	}
	ft_putchar('\n');
}

void	print_error(const char *par, enum e_errors n, t_bool is_exit)
{
	ft_putstr(g_error_text[0]);
	ft_putstr(g_error_text[n]);
	ft_putendl(par);
	if (n == IAIC)
		ft_putendl(g_error_text[1]);
	else if (n == UNOPT)
		ft_putendl(g_error_text[2]);
	if (is_exit)
		exit(n);
}
