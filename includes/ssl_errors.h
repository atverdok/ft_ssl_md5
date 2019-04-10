/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_errors.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:14:21 by atverdok          #+#    #+#             */
/*   Updated: 2019/04/03 18:14:39 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SSL_ERRORS_H
# define SSL_ERRORS_H

static char *g_error_text[] = {
	"ft_ssl: Error: ",
	"Standard commands:\n\nMessage Digest commands:\nmd5\nsha224\nsha256\
	\nsha384\nsha512",
	"Standard options:\n-p, echo STDIN to STDOUT and append the checksum to\
	STDOUT\n-q, quiet mode\n-r, reverse the format of the output\n-s, print\
	the sum of the given string, [-s string]",
	"usage: ft_ssl command [command opts] [command args]",
	"unknown option: ",
	" No such file or directory: ",
	" invalid command: "

};

enum	e_errors {
	USAGE = 3,
	UNOPT,
	NSFOD,
	IAIC,
};

#endif
