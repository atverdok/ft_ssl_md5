/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_message_addition.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 10:35:35 by atverdok          #+#    #+#             */
/*   Updated: 2019/04/09 10:37:06 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"
#include "./md5.h"

void	put_uint32(t_uchar *output, const uint32_t *input, uint32_t shift)
{
	output[shift + 0] = (t_uchar)(*input & 0xff);
	output[shift + 1] = (t_uchar)(*input >> 8 & 0xff);
	output[shift + 2] = (t_uchar)(*input >> 16 & 0xff);
	output[shift + 3] = (t_uchar)(*input >> 24 & 0xff);
}

void	add_len(t_md5_ctx *context)
{
	uint32_t high_bytes;
	uint32_t low_bytes;

	high_bytes = (context->count[0] >> 29) | (context->count[1] << 3);
	low_bytes = (context->count[0] << 3);
	put_uint32(context->buffer, &low_bytes, 56);
	put_uint32(context->buffer, &high_bytes, 60);
}

void	count_len(t_md5_ctx *context, size_t len_read)
{
	context->count[0] += (uint32_t)len_read;
	context->count[0] &= 0xFFFFFFFF;
	if (context->count[0] < (uint32_t)len_read)
		context->count[1]++;
}

void	alignment(t_md5_ctx *context, size_t len_read)
{
	if (len_read < 64)
	{
		*((t_uchar *)(context->buffer + len_read)) = 0x80;
		if (len_read < 56)
			return ;
		md5_raund(context);
		ft_bzero(context->buffer, MAX_READ);
	}
	else
	{
		md5_raund(context);
		ft_bzero(context->buffer, MAX_READ);
		*((t_uchar *)(context->buffer)) = 0x80;
	}
}
