/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 23:22:49 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/22 02:04:32 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_length(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	src_length;
	unsigned int	dst_length;
	unsigned int	i;

	src_length = str_length(src);
	dst_length = str_length(dest);
	i = 0;
	if (size < 1)
		return (src_length + size);
	dest += dst_length;
	while (src[i] && i + dst_length < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	if (size < dst_length)
		return (src_length + size);
	else
		return (dst_length + src_length);
}
