/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:16:30 by atverdok          #+#    #+#             */
/*   Updated: 2019/04/03 18:16:44 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA_384_512_H
# define SHA_384_512_H

# include <stdint.h>

# include "../ft_sha.h"
# include "sha_384_512_constants.h"

# define EP0_512(x) (ROTRIGHT(x,28) ^ ROTRIGHT(x,34) ^ ROTRIGHT(x,39))
# define EP1_512(x) (ROTRIGHT(x,14) ^ ROTRIGHT(x,18) ^ ROTRIGHT(x,41))
# define SIG0_512(x) (ROTRIGHT(x,1) ^ ROTRIGHT(x,8) ^ ((x) >> 7))
# define SIG1_512(x) (ROTRIGHT(x,19) ^ ROTRIGHT(x,61) ^ ((x) >> 6))

/*
** sha_384_512.c
*/
char	*sha512(int fd, char command, const char *str);
char	*sha384(int fd, char command, const char *str);

/*
** sha_384_512_init.c
*/
void	sha384_init(t_sha512_ctx *contex);
void	sha512_init(t_sha512_ctx *contex);

/*
** sha_384_512_digest.c
*/
char	*get_message_digest_384(t_sha512_ctx *contex);
char	*get_message_digest_512(t_sha512_ctx *contex);

/*
** sha_384_512_algo.c
*/
void	sha512_raund(t_sha512_ctx *contex);

/*
** sha_384_512_message_addition.c
*/
void	add_len_512(t_sha512_ctx *context);
void	count_len_512(t_sha512_ctx *context, size_t len_read);
void	alignment_512(t_sha512_ctx *context, size_t len_read);

#endif
