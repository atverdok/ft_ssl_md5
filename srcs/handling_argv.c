/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 10:37:16 by atverdok          #+#    #+#             */
/*   Updated: 2019/04/10 10:37:21 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

/*
** command - 1 byte
** 0000 0000
** 0000 srqp
*/

int		parse_flags(char const **argv, char *command)
{
	int i;

	i = 0;
	while (argv[++i] != NULL)
	{
		if ((ft_strnstr(argv[i], "-", 1)))
		{
			if (!ft_strcmp(argv[i], "-p"))
				*command |= FLAG_P;
			else if (!ft_strcmp(argv[i], "-q"))
				*command |= FLAG_Q;
			else if (!ft_strcmp(argv[i], "-r"))
				*command |= FLAG_R;
			else if (!ft_strcmp(argv[i], "-s") && argv[i + 1])
			{
				*command |= FLAG_S;
				return (++i);
			}
			else
				print_error(*argv, UNOPT, TRUE);
		}
		else
			break ;
	}
	return (i);
}

void	handle_argv_file(char const **argv_ptr, char flags,\
				t_algoritm *algo)
{
	int	fd;

	while (*argv_ptr != NULL)
	{
		if ((fd = open(*argv_ptr, O_RDONLY)) == -1)
		{
			print_error(*(argv_ptr++), NSFOD, FALSE);
			continue;
		}
		print_out(*(argv_ptr++), algo->func(fd, flags, NULL), \
				flags, algo->print);
		close(fd);
	}
}

void	handle_argv(int argc, char const **argv, t_algoritm *algo)
{
	char	flags;
	int		i;

	flags = 0;
	i = parse_flags(argv, &flags);
	argc--;
	if (!(argc - i) || (flags & FLAG_P))
	{
		ft_putendl(algo->func(STDIN_FILENO, flags, NULL));
		flags ^= FLAG_P;
	}
	if ((flags & FLAG_S))
	{
		print_out(argv[i], algo->func(0, flags, argv[i]), \
				flags, algo->print);
		flags ^= FLAG_S;
		if (argv[i])
			i++;
	}
	handle_argv_file((argv + i), flags, algo);
}
