/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:16:30 by atverdok          #+#    #+#             */
/*   Updated: 2019/04/03 18:16:44 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA_224_256_H
# define SHA_224_256_H

# include "../ft_sha.h"
# include "sha_224_256_constants.h"

# define EP0(x) (ROTRIGHT(x,2) ^ ROTRIGHT(x,13) ^ ROTRIGHT(x,22))
# define EP1(x) (ROTRIGHT(x,6) ^ ROTRIGHT(x,11) ^ ROTRIGHT(x,25))
# define SIG0(x) (ROTRIGHT(x,7) ^ ROTRIGHT(x,18) ^ ((x) >> 3))
# define SIG1(x) (ROTRIGHT(x,17) ^ ROTRIGHT(x,19) ^ ((x) >> 10))

/*
** sha_224_256.c
*/
char	*sha256(int fd, char command, const char *str);
char	*sha224(int fd, char command, const char *str);

/*
** sha_224_256_init.c
*/
void	sha224_init(t_sha256_ctx *contex);
void	sha256_init(t_sha256_ctx *contex);

/*
** sha_224_256_digest.c
*/
char	*get_message_digest_224(t_sha256_ctx *contex);
char	*get_message_digest_256(t_sha256_ctx *contex);

/*
** sha_224_256_algo.c
*/
void	sha256_raund(t_sha256_ctx *contex);

/*
** sha_224_256_message_addition.c
*/
void	add_len_256(t_sha256_ctx *context);
void	count_len_256(t_sha256_ctx *context, size_t len_read);
void	alignment_256(t_sha256_ctx *context, size_t len_read);

#endif
