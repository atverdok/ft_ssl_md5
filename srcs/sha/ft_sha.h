/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 09:49:58 by atverdok          #+#    #+#             */
/*   Updated: 2019/04/09 10:10:07 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA_H
# define FT_SHA_H

# include <stdint.h>
# include <string.h>
# include "../../includes/rot.h"

# define CH(x,y,z) (((x) & (y)) ^ (~(x) & (z)))
# define MAJ(x,y,z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))

typedef unsigned char	t_uchar;

/*
** state: (ABCDEFGH)
** bitlen: number of bits, 64
** buffer: input buffer
*/
typedef struct		s_sha256_ctx
{
	uint64_t		bitlen;
	uint32_t		state[8];
	unsigned char	buffer[64];
}					t_sha256_ctx;

/*
** state: (ABCDEFGH)
** count: number of bits
** buffer: input buffer
*/
typedef struct		s_sha512_ctx
{
	uint64_t		count[2];
	uint64_t		state[8];
	unsigned char	buffer[128];
}					t_sha512_ctx;

#endif
