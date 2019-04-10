/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:15:29 by atverdok          #+#    #+#             */
/*   Updated: 2019/04/03 18:15:48 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_H
# define MD5_H

# include <stddef.h>

# include "../../includes/rot.h"
# include "md5_constants.h"

/*
** state: (ABCD)
** count: number of bits, modulo 2^64 (lsb first)
** buffer: input buffer
*/
typedef struct	s_md5_ctx
{
	uint32_t	state[4];
	uint32_t	count[2];
	t_uchar		buffer[64];
}				t_md5_ctx;

/*
** md5.c
*/
char			*md5(int fd, char command, const char *in);

/*
** md5_init.c
*/
void			md5_init(t_md5_ctx *contex);

/*
** md5_digest.c
*/
char			*get_message_digest(t_md5_ctx *contex);

/*
** md5_algo.c
*/
void			md5_raund(t_md5_ctx *contex);

/*
** md5_message_addition.c
*/
void			add_len(t_md5_ctx *context);
void			count_len(t_md5_ctx *context, size_t len_read);
void			alignment(t_md5_ctx *context, size_t len_read);

#endif
