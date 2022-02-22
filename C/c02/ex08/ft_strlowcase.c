/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:41:12 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/22 02:02:14 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef char	(*t_on_character)(char c);

void	apply_on_string(char *str, t_on_character func)
{
	while (*str)
	{
		*str = func(*str);
		str++;
	}
}

char	to_lowercase(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c + 'a' - 'A');
	}
	return (c);
}

char	*ft_strlowcase(char *str)
{
	apply_on_string(str, to_lowercase);
	return (str);
}
