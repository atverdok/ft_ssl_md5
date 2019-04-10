/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:15:05 by atverdok          #+#    #+#             */
/*   Updated: 2019/04/03 18:15:13 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"
#include "./md5.h"

void	processing_fd(t_md5_ctx *context, int fd, char command)
{
	size_t	len_read;
	char	str[MAX_READ];

	ft_memset(str, 0, MAX_READ);
	while ((len_read = read(fd, &str, MAX_READ)))
	{
		if ((command & FLAG_P))
			write(STDOUT_FILENO, str, len_read);
		count_len(context, len_read);
		ft_memcpy(context->buffer, str, len_read);
		alignment(context, len_read);
		ft_bzero(str, MAX_READ);
	}
}

void	processing_str(t_md5_ctx *context, const char *str, size_t len)
{
	size_t i;

	count_len(context, len);
	i = 0;
	while (i < len)
	{
		ft_memcpy(context->buffer, (str + i), (((len - i) > MAX_READ) \
			? MAX_READ : (len - i)));
		alignment(context, (len - i));
		i += MAX_READ;
	}
}

char	*md5(int fd, char command, const char *str)
{
	t_md5_ctx	context;
	char		*string;
	size_t		len;

	ft_memset(&context, 0, sizeof(context));
	md5_init(&context);
	len = ((str == NULL) ? 0 : ft_strlen(str));
	if (str != NULL)
		processing_str(&context, str, len);
	else if (fd)
		processing_fd(&context, fd, command);
	else
	{
		string = read_stdin(fd, &len);
		processing_str(&context, string, len);
		if ((command & FLAG_P))
			write(STDOUT_FILENO, string, len);
		if (len == MAX_INPUT_STDIN)
			processing_fd(&context, fd, command);
		free(string);
		string = NULL;
	}
	add_len(&context);
	md5_raund(&context);
	return (get_message_digest(&context));
}
