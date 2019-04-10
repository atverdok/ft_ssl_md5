/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 10:28:44 by atverdok          #+#    #+#             */
/*   Updated: 2019/04/09 10:28:51 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./md5.h"
#include "../../includes/ft_ssl.h"

void	md5_init(t_md5_ctx *contex)
{
	contex->state[0] = 0x67452301;
	contex->state[1] = 0xefcdab89;
	contex->state[2] = 0x98badcfe;
	contex->state[3] = 0x10325476;
}
