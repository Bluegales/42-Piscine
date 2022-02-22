/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 11:33:31 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/22 02:02:31 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlength(char *string)
{
	int	i;

	i = 0;
	while (*string)
	{
		i++;
		string++;
	}
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int n)
{
	int	src_length;
	int	size;

	size = n;
	src_length = ft_strlength(src);
	if (size == 0)
		return (src_length);
	while (size > 0)
	{
		*dest = *src;
		if (*dest == 0)
			break ;
		dest++;
		src++;
		size--;
	}
	if (size == 0)
	{
		dest--;
	}
	*dest = 0;
	return (src_length);
}
