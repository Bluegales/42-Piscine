/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:50:39 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/22 02:04:08 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*hay;
	char	*needle;
	int		i;

	i = 0;
	hay = str;
	needle = to_find;
	if (!*needle)
		return (hay);
	while (*hay)
	{
		needle = to_find;
		while (*hay && *hay == *needle)
		{
			hay++;
			needle++;
		}
		if (!*needle)
			return (hay + (to_find - needle));
		hay = ++i + str;
	}
	return (0);
}
