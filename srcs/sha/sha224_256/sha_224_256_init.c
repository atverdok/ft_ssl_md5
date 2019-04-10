/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha_224_256_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 19:10:09 by atverdok          #+#    #+#             */
/*   Updated: 2019/04/08 19:10:13 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_ssl.h"
#include "sha_224_256.h"

void	sha224_init(t_sha256_ctx *contex)
{
	contex->state[0] = 0xc1059ed8;
	contex->state[1] = 0x367cd507;
	contex->state[2] = 0x3070dd17;
	contex->state[3] = 0xf70e5939;
	contex->state[4] = 0xffc00b31;
	contex->state[5] = 0x68581511;
	contex->state[6] = 0x64f98fa7;
	contex->state[7] = 0xbefa4fa4;
}

void	sha256_init(t_sha256_ctx *contex)
{
	contex->state[0] = 0x6a09e667;
	contex->state[1] = 0xbb67ae85;
	contex->state[2] = 0x3c6ef372;
	contex->state[3] = 0xa54ff53a;
	contex->state[4] = 0x510e527f;
	contex->state[5] = 0x9b05688c;
	contex->state[6] = 0x1f83d9ab;
	contex->state[7] = 0x5be0cd19;
}
