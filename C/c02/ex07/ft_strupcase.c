/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:41:12 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/22 02:02:05 by pfuchs           ###   ########.fr       */
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

char	change_to_uppercase(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c + 'A' - 'a');
	}
	return (c);
}

char	*ft_strupcase(char *str)
{
	apply_on_string(str, change_to_uppercase);
	return (str);
}
