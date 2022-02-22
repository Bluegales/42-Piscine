/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:41:51 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/06 00:47:03 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Fills the array with the correct offset
void	set_offset(char *offset, void *data)
{
	unsigned long	offset_val;
	int				i;

	offset_val = (unsigned long)data;
	i = 0;
	while (i < 16)
	{
		offset[15 - i] = "0123456789abcdefgh"[offset_val >> (i * 4) & 0xf];
		i++;
	}
}

// Fills the hex with the correct hex
void	set_hex_ascii(char *hex, char *ascii, unsigned char *data)
{
	int	i;

	i = 0;
	while (i <= 16)
	{
		*ascii = '.';
		if (*data >= 32 && *data < 127)
		{
			*ascii = *data;
		}
		ascii++;
		*hex = "0123456789abcdefgh"[*data / 16];
		hex++;
		*hex = "0123456789abcdefgh"[*data % 16];
		hex++;
		if (i % 2 == 1)
		{
			*hex = ' ';
			hex++;
		}
		data++;
		i++;
	}
}

void	print_output(char *offset, char *hex, char *ascii, int size)
{
	int	spaces;

	write(1, offset, 16);
	write(1, ": ", 2);
	if (size >= 16)
	{
		write(1, hex, 32 + 8);
		write(1, ascii, 16);
	}
	else
	{
		spaces = 40 - (size * 2 + size / 2);
		write(1, hex, size * 2 + size / 2);
		write(1, "                                        ", spaces);
		write(1, ascii, size);
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char			offset[30];
	char			hex[32 + 20];
	char			ascii[20];
	unsigned char	*address;

	address = addr;
	if (addr == 0)
		return (0);
	if (size == 0)
		return (addr);
	while (1)
	{
		set_offset(offset, address);
		set_hex_ascii(hex, ascii, address);
		print_output(offset, hex, ascii, size);
		address += 16;
		if (size <= 16)
			return (addr);
		size -= 16;
	}
	return (addr);
}
