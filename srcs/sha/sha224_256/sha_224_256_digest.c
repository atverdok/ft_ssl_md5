/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha_224_256_digest.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 19:09:48 by atverdok          #+#    #+#             */
/*   Updated: 2019/04/08 19:09:55 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_ssl.h"
#include "sha_224_256.h"

char	*get_message_digest_224(t_sha256_ctx *contex)
{
	static const char	*base = "0123456789abcdef";
	static char			mes_digest[56] = {0};
	int					i;
	int					j;
	int					q;

	q = 0;
	i = -1;
	ft_bzero(mes_digest, 56);
	while (++i < 7)
	{
		j = 6;
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

char	*get_message_digest_256(t_sha256_ctx *contex)
{
	static const char	*base = "0123456789abcdef";
	static char			mes_digest[64] = {0};
	int					i;
	int					j;
	int					q;

	q = 0;
	i = -1;
	ft_bzero(mes_digest, 64);
	while (++i < 8)
	{
		j = 6;
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
