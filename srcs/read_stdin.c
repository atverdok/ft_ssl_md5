/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atverdok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 14:58:37 by atverdok          #+#    #+#             */
/*   Updated: 2019/04/10 10:18:51 by atverdok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void	*ft_realoc(void *ptr, size_t size)
{
	char *new;

	if (!size)
		ft_memdel(&ptr);
	if (ptr)
	{
		new = ft_memalloc(sizeof(char) * size);
		ft_memcpy(new, ptr, size);
		ft_memdel(&ptr);
		return (new);
	}
	return (ptr);
}

char	*read_stdin(int fd, size_t *len)
{
	size_t	len_read;
	char	str[MAX_INPUT_STDIN];
	char	*data;

	data = ft_strnew(0);
	ft_bzero(str, MAX_INPUT_STDIN);
	while ((len_read = read(fd, &str, MAX_INPUT_STDIN)))
	{
		data = ft_realoc(data, (*len + len_read));
		ft_memcpy((data + *len), str, len_read);
		*len += len_read;
		ft_bzero(str, len_read);
		if (len_read == MAX_INPUT_STDIN)
			break ;
	}
	return (data);
}

char	*read_stdin_512(int fd, size_t *len)
{
	size_t	len_read;
	char	str[MAX_INPUT_STDIN_512];
	char	*data;

	data = ft_strnew(0);
	ft_bzero(str, MAX_INPUT_STDIN_512);
	while ((len_read = read(fd, &str, MAX_INPUT_STDIN_512)))
	{
		data = ft_realoc(data, (*len + len_read));
		ft_memcpy((data + *len), str, len_read);
		*len += len_read;
		ft_bzero(str, len_read);
		if (len_read == MAX_INPUT_STDIN_512)
			break ;
	}
	return (data);
}
