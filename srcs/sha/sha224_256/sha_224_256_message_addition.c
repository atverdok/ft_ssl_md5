/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha_224_256_message_addition.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 08:15:46 by atverdok          #+#    #+#             */
/*   Updated: 2019/04/09 08:16:01 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_ssl.h"
#include "sha_224_256.h"

void	add_len_256(t_sha256_ctx *context)
{
	context->buffer[63] = context->bitlen;
	context->buffer[62] = context->bitlen >> 8;
	context->buffer[61] = context->bitlen >> 16;
	context->buffer[60] = context->bitlen >> 24;
	context->buffer[59] = context->bitlen >> 32;
	context->buffer[58] = context->bitlen >> 40;
	context->buffer[57] = context->bitlen >> 48;
	context->buffer[56] = context->bitlen >> 56;
}

void	count_len_256(t_sha256_ctx *context, size_t len_read)
{
	if (len_read == 64)
		context->bitlen += 512;
	else
		context->bitlen += len_read * 8;
}

void	alignment_256(t_sha256_ctx *context, size_t len_read)
{
	if (len_read < 64)
	{
		*((t_uchar *)(context->buffer + len_read)) = 0x80;
		if (len_read < 56)
			return ;
		sha256_raund(context);
		ft_bzero(context->buffer, MAX_READ);
	}
	else
	{
		sha256_raund(context);
		ft_bzero(context->buffer, MAX_READ);
		*((t_uchar *)(context->buffer)) = 0x80;
	}
}
