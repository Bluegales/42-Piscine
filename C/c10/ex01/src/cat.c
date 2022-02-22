/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 14:53:25 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/14 04:00:24 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.h"
#include "input.h"
#include "write_string.h"

#include <fcntl.h> //file
#include <errno.h> //erno
#include <unistd.h> //write
#include <string.h> //strerror
#include <libgen.h> //basename

void	display_error(char *file_path, char *exec)
{
	write_error(basename(exec));
	write_error(": ");
	write_error(file_path);
	write_error(": ");
	write_error(strerror(errno));
	write_error("\n");
}

int	in_out_loop(void)
{
	int		size_read;
	char	buffer[0xff];

	while (1)
	{
		size_read = read(0, buffer, 0xff);
		if (size_read > 0)
			write(1, buffer, size_read);
		if (size_read < 0)
			return (1);
	}
}

int	cat(char *file_path, char *exec)
{
	int		file;
	int		size_read;
	char	buffer[200];

	file = open(file_path, O_RDONLY);
	if (file < 0)
	{
		display_error(file_path, exec);
		return (1);
	}
	while (1)
	{
		size_read = read(file, buffer, 200);
		if (size_read > 0)
			write(1, buffer, size_read);
		if (size_read == 0)
			break ;
		if (size_read < 0)
		{
			display_error(file_path, exec);
			return (1);
		}
	}
	close(file);
	return (0);
}
