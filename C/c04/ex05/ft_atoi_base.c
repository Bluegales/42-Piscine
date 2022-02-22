/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 10:12:46 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/22 02:08:16 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	valid_base(char *base, int *length)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] < 32)
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = 0;
		while (base[j])
		{
			if (base[j] == base[i] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	*length = i;
	return (1);
}

int	power(int x, unsigned int y)
{
	if (y == 0)
	{
		return (1);
	}
	else if (y % 2 == 0)
	{
		return (power(x, y / 2) * power(x, y / 2));
	}
	else
	{
		return (x * power(x, y / 2) * power(x, y / 2));
	}
}

void	create_convert(char *base, int *convert)
{
	int	i;

	i = 0;
	while (i < 260)
	{
		convert[i] = -1;
		i++;
	}
	i = 0;
	while (base[i])
	{
		convert[(unsigned char)base[i]] = i;
		i++;
	}
}

int	get_number(char *str, int *convert, int base_size)
{
	int		i;
	long	number;
	int		number_length;
	int		digit;

	number = 0;
	i = 0;
	while (str[i])
	{
		digit = convert[(unsigned char)str[i]];
		if (digit == -1)
			break ;
		i++;
	}
	number_length = i;
	while (i > 0)
	{
		i--;
		digit = convert[(unsigned char)str[i]];
		number += digit * power(base_size, number_length - i - 1);
	}
	return (number);
}

int	ft_atoi_base(char *str, char *base)
{
	int		sign;
	int		base_size;
	int		convert[300];

	if (!valid_base(base, &base_size))
		return (0);
	sign = 1;
	if (!*str)
		return (0);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	create_convert(base, convert);
	return (get_number(str, convert, base_size) * sign);
}
