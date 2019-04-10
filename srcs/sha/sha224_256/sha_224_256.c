/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha_224_256.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:47:09 by atverdok          #+#    #+#             */
/*   Updated: 2019/04/08 17:47:22 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_ssl.h"
#include "sha_224_256.h"

void	processing_fd_256(t_sha256_ctx *context, int fd, char command)
{
	char	str[MAX_READ];
	size_t	len_read;

	ft_memset(str, 0, MAX_READ);
	while ((len_read = read(fd, &str, MAX_READ)))
	{
		if ((command & FLAG_P) && !fd)
			write(STDOUT_FILENO, str, len_read);
		count_len_256(context, len_read);
		ft_memcpy(context->buffer, str, len_read);
		alignment_256(context, len_read);
		ft_bzero(str, MAX_READ);
	}
}

void	processing_str_256(t_sha256_ctx *context, const char *str, size_t len)
{
	size_t i;

	count_len_256(context, len);
	i = 0;
	while (i < len)
	{
		ft_memcpy(context->buffer, (str + i), (((len - i) > MAX_READ) \
			? MAX_READ : (len - i)));
		alignment_256(context, (len - i));
		i += MAX_READ;
	}
}

char	*sha256(int fd, char command, const char *str)
{
	t_sha256_ctx	context;
	char			*string;
	size_t			len;

	ft_memset(&context, 0, sizeof(context));
	sha256_init(&context);
	len = ((str == NULL) ? 0 : ft_strlen(str));
	if (str != NULL)
		processing_str_256(&context, str, len);
	else if (fd)
		processing_fd_256(&context, fd, command);
	else
	{
		string = read_stdin(fd, &len);
		processing_str_256(&context, string, len);
		if ((command & FLAG_P))
			write(STDOUT_FILENO, string, len);
		if (len == MAX_INPUT_STDIN)
			processing_fd_256(&context, fd, command);
		free(string);
	}
	add_len_256(&context);
	sha256_raund(&context);
	return (get_message_digest_256(&context));
}

char	*sha224(int fd, char command, const char *str)
{
	t_sha256_ctx	context;
	char			*string;
	size_t			len;

	ft_memset(&context, 0, sizeof(context));
	sha224_init(&context);
	len = ((str == NULL) ? 0 : ft_strlen(str));
	if (str != NULL)
		processing_str_256(&context, str, len);
	else if (fd)
		processing_fd_256(&context, fd, command);
	else
	{
		string = read_stdin(fd, &len);
		processing_str_256(&context, string, len);
		if ((command & FLAG_P))
			write(STDOUT_FILENO, string, len);
		if (len == MAX_INPUT_STDIN)
			processing_fd_256(&context, fd, command);
		free(string);
	}
	add_len_256(&context);
	sha256_raund(&context);
	return (get_message_digest_224(&context));
}
