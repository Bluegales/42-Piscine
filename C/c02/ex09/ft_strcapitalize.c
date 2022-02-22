/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:40:22 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/22 02:02:25 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char p)
{
	if ((p >= 'a' && p <= 'z') || (p >= 'A' && p <= 'Z'))
	{
		return (1);
	}
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	char	*original;
	char	p;

	original = str;
	if (!*str)
		return (str);
	if (*str >= 'a' && *str <= 'z')
		*str = *str - 'a' + 'A';
	while (*str)
	{
		str++;
		p = *(str - 1);
		if (ft_str_is_alpha(p) || (p >= '0' && p <= '9'))
		{
			if (*str >= 'A' && *str <= 'Z')
				*str = *str - 'A' + 'a';
		}
		else
		{
			if (*str >= 'a' && *str <= 'z')
				*str = *str - 'a' + 'A';
		}
	}
	return (original);
}
