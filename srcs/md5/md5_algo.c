/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:19:26 by atverdok          #+#    #+#             */
/*   Updated: 2019/04/09 11:20:24 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./md5.h"

void	compres_func_raund_md5(uint32_t *tmp, uint32_t *w)
{
	short int i;

	i = -1;
	while (++i < 64)
	{
		if (i < 16)
			tmp[4] = (tmp[1] & tmp[2]) | ((~tmp[1]) & tmp[3]);
		else if (i < 32)
			tmp[4] = (tmp[3] & tmp[1]) | ((~tmp[3]) & tmp[2]);
		else if (i < 48)
			tmp[4] = tmp[1] ^ tmp[2] ^ tmp[3];
		else
			tmp[4] = tmp[2] ^ (tmp[1] | (~tmp[3]));
		tmp[5] = tmp[3];
		tmp[3] = tmp[2];
		tmp[2] = tmp[1];
		tmp[1] = tmp[1] + ROTLEFT((tmp[0] + tmp[4] + g_t[i] \
					+ w[g_shift[i]]), g_s[i]);
		tmp[0] = tmp[5];
	}
}

void	md5_raund(t_md5_ctx *contex)
{
	uint32_t	*w;
	uint32_t	tmp[6];
	short int	i;

	w = (uint32_t *)(contex->buffer);
	i = -1;
	while (++i < 4)
		tmp[i] = contex->state[i];
	compres_func_raund_md5(tmp, w);
	i = -1;
	while (++i < 4)
		contex->state[i] += tmp[i];
}
