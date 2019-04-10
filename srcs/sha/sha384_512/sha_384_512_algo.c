/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha_384_512_algo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 09:32:17 by atverdok          #+#    #+#             */
/*   Updated: 2019/04/09 09:42:20 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_ssl.h"
#include "sha_384_512.h"

void	pack64(const unsigned char *str, uint64_t *x)
{
	*x = ((uint64_t)*((str) + 7)) | ((uint64_t)*((str) + 6) << 8) \
		| ((uint64_t)*((str) + 5) << 16) | ((uint64_t)*((str) + 4) << 24) \
		| ((uint64_t)*((str) + 3) << 32) | ((uint64_t)*((str) + 2) << 40) \
		| ((uint64_t)*((str) + 1) << 48) | ((uint64_t)*((str) + 0) << 56);
}

void	prepare_raund_512(t_sha512_ctx *contex, uint64_t *m)
{
	short int i;

	i = -1;
	while (++i < 16)
		pack64(&contex->buffer[i << 3], &m[i]);
	i--;
	while (++i < 80)
		m[i] = m[i - 16] + SIG0_512(m[i - 15]) + m[i - 7] + SIG1_512(m[i - 2]);
}

/*
** tmp[0] - a
** tmp[1] - b
** tmp[2] - c
** tmp[3] - d
** tmp[4] - e
** tmp[5] - f
** tmp[6] - g
** tmp[7] - h
** tmp[8] - tmp1
** tmp[9] - tmp2
*/

void	compres_func_raund_512(uint64_t *tmp, uint64_t *m)
{
	short int i;

	i = -1;
	while (++i < 80)
	{
		tmp[8] = tmp[7] + EP1_512(tmp[4]) + CH(tmp[4], tmp[5], tmp[6]) \
			+ g_sha512_k[i] + m[i];
		tmp[9] = EP0_512(tmp[0]) + MAJ(tmp[0], tmp[1], tmp[2]);
		tmp[7] = tmp[6];
		tmp[6] = tmp[5];
		tmp[5] = tmp[4];
		tmp[4] = tmp[3] + tmp[8];
		tmp[3] = tmp[2];
		tmp[2] = tmp[1];
		tmp[1] = tmp[0];
		tmp[0] = tmp[8] + tmp[9];
	}
}

void	sha512_raund(t_sha512_ctx *contex)
{
	uint64_t	m[80];
	uint64_t	tmp[10];
	short int	i;

	prepare_raund_512(contex, m);
	i = -1;
	while (++i < 8)
		tmp[i] = contex->state[i];
	compres_func_raund_512(tmp, m);
	i = -1;
	while (++i < 8)
		contex->state[i] += tmp[i];
}
