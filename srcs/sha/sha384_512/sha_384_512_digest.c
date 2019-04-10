/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha_384_512_digest.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 09:02:38 by atverdok          #+#    #+#             */
/*   Updated: 2019/04/09 09:02:45 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_ssl.h"
#include "sha_384_512.h"

char	*get_message_digest_512(t_sha512_ctx *contex)
{
	static const char	*base = "0123456789abcdef";
	static char			mes_digest[128] = {0};
	int					i;
	int					j;
	int					q;

	q = 0;
	i = -1;
	ft_bzero(mes_digest, 128);
	while (++i < 8)
	{
		j = 14;
		while (j > -1)
		{
			mes_digest[q] = base[(contex->state[i] >> (j * 4 + 4)) & 0xf];
			mes_digest[q + 1] = base[(contex->state[i] >> (j * 4)) & 0xf];
			j -= 2;
			q += 2;
		}
	}
	return (mes_digest);
}

char	*get_message_digest_384(t_sha512_ctx *contex)
{
	static const char	*base = "0123456789abcdef";
	static char			mes_digest[96] = {0};
	int					i;
	int					j;
	int					q;

	q = 0;
	i = -1;
	ft_bzero(mes_digest, 96);
	while (++i < 6)
	{
		j = 14;
		while (j > -1)
		{
			mes_digest[q] = base[(contex->state[i] >> (j * 4 + 4)) & 0xf];
			mes_digest[q + 1] = base[(contex->state[i] >> (j * 4)) & 0xf];
			j -= 2;
			q += 2;
		}
	}
	return (mes_digest);
}
