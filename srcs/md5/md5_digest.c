/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_digest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 10:30:42 by atverdok          #+#    #+#             */
/*   Updated: 2019/04/09 10:32:14 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"
#include "./md5.h"

char	*get_message_digest(t_md5_ctx *contex)
{
	static const char	*base = "0123456789abcdef";
	static char			mes_digest[32] = {0};
	int					i;
	int					j;
	int					q;

	q = 0;
	i = -1;
	ft_bzero(mes_digest, 32);
	while (++i < 4)
	{
		j = 0;
		while (j < 8)
		{
			mes_digest[q] = base[(contex->state[i] >> (j * 4 + 4)) & 0xf];
			mes_digest[q + 1] = base[(contex->state[i] >> (j * 4)) & 0xf];
			j += 2;
			q += 2;
		}
	}
	return (mes_digest);
}
