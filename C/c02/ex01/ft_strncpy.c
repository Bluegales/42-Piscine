/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 08:40:43 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/22 02:00:43 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char	*it;

	it = dest;
	while (n)
	{
		if (*src)
		{
			*it = *src;
			src++;
		}
		else
		{
			*it = 0;
		}
		it++;
		n--;
	}
	return (dest);
}
