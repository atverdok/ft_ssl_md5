/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:10:36 by atverdok          #+#    #+#             */
/*   Updated: 2019/04/09 12:28:36 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5/md5.h"
#include "sha/sha224_256/sha_224_256.h"
#include "sha/sha384_512/sha_384_512.h"

static t_algoritm	g_algoritms[] = {
	{"md5", "MD5", md5},
	{"sha224", "SHA224", sha224},
	{"sha256", "SHA256", sha256},
	{"sha384", "SHA384", sha384},
	{"sha512", "SHA512", sha512}
};

t_algoritm			*get_has_func(char const *argv)
{
	int i;
	int count_algo;

	i = -1;
	count_algo = sizeof(g_algoritms) / sizeof(*g_algoritms);
	while (++i < count_algo)
	{
		if (!ft_strcmp(argv, g_algoritms[i].name))
			return (&g_algoritms[i]);
	}
	print_error(argv, IAIC, FALSE);
	exit(UNOPT);
}

int					main(int argc, char const **argv)
{
	if (argc > 1)
		handle_argv(argc, (argv + 1), get_has_func(argv[1]));
	else
		ft_putendl_fd(g_error_text[USAGE], 2);
	return (0);
}
