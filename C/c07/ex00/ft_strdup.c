/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:23:17 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/22 02:11:08 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src)
{
	char	*it;

	it = dest;
	while (*src)
	{
		*it = *src;
		it++;
		src++;
	}
	*it = 0;
	return (dest);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*new_str;

	i = 0;
	while (src[i])
		i++;
	new_str = (char *) malloc(i + 1);
	ft_strcpy(new_str, src);
	return (new_str);
}
