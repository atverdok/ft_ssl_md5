/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:16:11 by atverdok          #+#    #+#             */
/*   Updated: 2019/04/03 18:16:20 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_ssl.h"
#include "sha_384_512.h"

void	processing_fd_512(t_sha512_ctx *context, int fd, char command)
{
	char	str[MAX_READ_512];
	size_t	len_read;

	ft_memset(str, 0, MAX_READ_512);
	while ((len_read = read(fd, &str, MAX_READ_512)))
	{
		if ((command & FLAG_P) && !fd)
			write(STDOUT_FILENO, str, len_read);
		count_len_512(context, len_read);
		ft_memcpy(context->buffer, str, len_read);
		alignment_512(context, len_read);
		ft_bzero(str, MAX_READ_512);
	}
}

void	processing_str_512(t_sha512_ctx *context, const char *str, size_t len)
{
	size_t i;

	count_len_512(context, len);
	i = 0;
	while (i < len)
	{
		ft_memcpy(context->buffer, (str + i), (((len - i) > MAX_READ_512) \
			? MAX_READ_512 : (len - i)));
		alignment_512(context, (len - i));
		i += MAX_READ_512;
	}
}

char	*sha512(int fd, char command, const char *str)
{
	t_sha512_ctx	context;
	char			*string;
	size_t			len;

	ft_memset(&context, 0, sizeof(context));
	sha512_init(&context);
	len = ((str == NULL) ? 0 : ft_strlen(str));
	if (str != NULL)
		processing_str_512(&context, str, len);
	else if (fd)
		processing_fd_512(&context, fd, command);
	else
	{
		string = read_stdin_512(fd, &len);
		processing_str_512(&context, string, len);
		if ((command & FLAG_P))
			write(STDOUT_FILENO, string, len);
		if (len == MAX_INPUT_STDIN_512)
			processing_fd_512(&context, fd, command);
		free(string);
	}
	add_len_512(&context);
	sha512_raund(&context);
	return (get_message_digest_512(&context));
}

char	*sha384(int fd, char command, const char *str)
{
	t_sha512_ctx	context;
	char			*string;
	size_t			len;

	ft_memset(&context, 0, sizeof(context));
	sha384_init(&context);
	len = ((str == NULL) ? 0 : ft_strlen(str));
	if (str != NULL)
		processing_str_512(&context, str, len);
	else if (fd)
		processing_fd_512(&context, fd, command);
	else
	{
		string = read_stdin_512(fd, &len);
		processing_str_512(&context, string, len);
		if ((command & FLAG_P))
			write(STDOUT_FILENO, string, len);
		if (len == MAX_INPUT_STDIN_512)
			processing_fd_512(&context, fd, command);
		free(string);
	}
	add_len_512(&context);
	sha512_raund(&context);
	return (get_message_digest_384(&context));
}
