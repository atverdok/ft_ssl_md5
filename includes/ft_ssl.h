/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:13:38 by atverdok          #+#    #+#             */
/*   Updated: 2019/04/03 18:14:01 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include <stdio.h>

/*
** uint32_t linux
*/
# include <stdint.h>

/*
** constant for open
*/
# include <fcntl.h>

/*
** MAX_INPUT
*/
# include <sys/param.h>

# include "../libft/libft.h"
# include "./ssl_errors.h"

# define MAX_READ 				64
# define MAX_READ_512 			128

# ifdef __linux__
#  define MAX_INPUT_STDIN		MAX_INPUT + 1 + MAX_READ
#  define MAX_INPUT_STDIN_512	MAX_INPUT + 1 + MAX_READ_512
# elif __APPLE__
#  define MAX_INPUT_STDIN		MAX_INPUT + MAX_READ
#  define MAX_INPUT_STDIN_512	MAX_INPUT + MAX_READ_512
# endif

# define FLAG_P 0x01
# define FLAG_Q 0x02
# define FLAG_R 0x04
# define FLAG_S 0x08

typedef char* (*t_has_function)(int fd, char command, const char *str);

typedef enum	e_bool {
	FALSE,
	TRUE
}				t_bool;

typedef struct	s_algoritm
{
	char			name[7];
	char			print[7];
	t_has_function	func;
}				t_algoritm;

/*
** read_stdin.c
*/
char			*read_stdin(int fd, size_t *len);
char			*read_stdin_512(int fd, size_t *len);

/*
** print.c
*/
void			print_out(const char *str, char *mes_digest, \
					char command, const char *name);
void			print_error(const char *par, enum e_errors n, \
					t_bool is_exit);

/*
** handling_argv.c
*/
void			handle_argv(int argc, char const **argv, t_algoritm *algo);

#endif
