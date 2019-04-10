/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha_384_512_message_addition.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 09:11:19 by atverdok          #+#    #+#             */
/*   Updated: 2019/04/09 09:14:47 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_ssl.h"
#include "sha_384_512.h"

void	put_uint64(t_uchar *output, const uint64_t *input, unsigned int shift)
{
	output[shift + 7] = (t_uchar)(*input & 0xff);
	output[shift + 6] = (t_uchar)(*input >> 8 & 0xff);
	output[shift + 5] = (t_uchar)(*input >> 16 & 0xff);
	output[shift + 4] = (t_uchar)(*input >> 24 & 0xff);
	output[shift + 3] = (t_uchar)(*input >> 32 & 0xff);
	output[shift + 2] = (t_uchar)(*input >> 40 & 0xff);
	output[shift + 1] = (t_uchar)(*input >> 48 & 0xff);
	output[shift + 0] = (t_uchar)(*input >> 56 & 0xff);
}

void	add_len_512(t_sha512_ctx *context)
{
	uint64_t high_bytes;
	uint64_t low_bytes;

	high_bytes = (context->count[0] >> 61);
	low_bytes = (context->count[0] << 3);
	put_uint64(context->buffer, &high_bytes, 112);
	put_uint64(context->buffer, &low_bytes, 120);
}

void	count_len_512(t_sha512_ctx *context, size_t len_read)
{
	context->count[0] += (uint64_t)len_read;
	context->count[0] &= 0xffffffffffffffff;
	if (context->count[0] < (uint64_t)len_read)
		context->count[1]++;
}

void	alignment_512(t_sha512_ctx *context, size_t len_read)
{
	if (len_read < MAX_READ_512)
	{
		*((t_uchar *)(context->buffer + len_read)) = 0x80;
		if (len_read < 112)
			return ;
		sha512_raund(context);
		ft_bzero(context->buffer, MAX_READ_512);
	}
	else
	{
		sha512_raund(context);
		ft_bzero(context->buffer, MAX_READ_512);
		*((t_uchar *)(context->buffer)) = 0x80;
	}
}
