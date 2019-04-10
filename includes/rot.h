/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 10:49:01 by atverdok          #+#    #+#             */
/*   Updated: 2019/04/10 10:49:09 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROT_H
# define ROT_H

# define ROTLEFT(a,b) (((a) << (b)) | ((a) >> ((sizeof(a)*8)-(b))))
# define ROTRIGHT(a,b) (((a) >> (b)) | ((a) << (((sizeof(a)*8)-(b)))))

#endif
