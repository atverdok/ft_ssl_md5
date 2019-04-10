/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha_384_512_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 08:29:38 by atverdok          #+#    #+#             */
/*   Updated: 2019/04/09 08:32:10 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha_384_512.h"

void	sha512_init(t_sha512_ctx *contex)
{
	contex->state[0] = 0x6a09e667f3bcc908;
	contex->state[1] = 0xbb67ae8584caa73b;
	contex->state[2] = 0x3c6ef372fe94f82b;
	contex->state[3] = 0xa54ff53a5f1d36f1;
	contex->state[4] = 0x510e527fade682d1;
	contex->state[5] = 0x9b05688c2b3e6c1f;
	contex->state[6] = 0x1f83d9abfb41bd6b;
	contex->state[7] = 0x5be0cd19137e2179;
}

void	sha384_init(t_sha512_ctx *contex)
{
	contex->state[0] = 0xcbbb9d5dc1059ed8;
	contex->state[1] = 0x629a292a367cd507;
	contex->state[2] = 0x9159015a3070dd17;
	contex->state[3] = 0x152fecd8f70e5939;
	contex->state[4] = 0x67332667ffc00b31;
	contex->state[5] = 0x8eb44a8768581511;
	contex->state[6] = 0xdb0c2e0d64f98fa7;
	contex->state[7] = 0x47b5481dbefa4fa4;
}
