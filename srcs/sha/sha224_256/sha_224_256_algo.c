/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha_224_256_algo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 19:10:28 by atverdok          #+#    #+#             */
/*   Updated: 2019/04/08 19:10:32 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_ssl.h"
#include "sha_224_256.h"

void	pack32(const unsigned char *str, uint32_t *x)
{
	*x = ((uint32_t)*((str) + 3))
		| ((uint32_t)*((str) + 2) << 8)
		| ((uint32_t)*((str) + 1) << 16)
		| ((uint32_t)*((str) + 0) << 24);
}

void	prepare_raund(t_sha256_ctx *contex, uint32_t *m)
{
	short int i;

	i = -1;
	while (++i < 16)
		pack32(&contex->buffer[i << 2], &m[i]);
	i--;
	while (++i < 64)
		m[i] = m[i - 16] + SIG0(m[i - 15]) + m[i - 7] + SIG1(m[i - 2]);
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

void	compres_func_raund(uint32_t *tmp, uint32_t *m)
{
	short int i;

	i = -1;
	while (++i < 64)
	{
		tmp[8] = tmp[7] + EP1(tmp[4]) + CH(tmp[4], tmp[5], tmp[6]) \
			+ g_sha256_k[i] + m[i];
		tmp[9] = EP0(tmp[0]) + MAJ(tmp[0], tmp[1], tmp[2]);
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

void	sha256_raund(t_sha256_ctx *contex)
{
	uint32_t	m[64];
	uint32_t	tmp[10];
	short int	i;

	prepare_raund(contex, m);
	i = -1;
	while (++i < 8)
		tmp[i] = contex->state[i];
	compres_func_raund(tmp, m);
	i = -1;
	while (++i < 8)
		contex->state[i] += tmp[i];
}
