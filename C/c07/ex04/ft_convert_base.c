/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:47:20 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/15 17:24:25 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// Main function get_number 
// returning the decimal number from str and base
int	ft_atoi_base(char *str, char *base);
// Simple power function
int	power(int x, unsigned int y);
// Checks for valid base
int	valid_base(char *base, int *length);

int	recursive_base(long number, int base_size, char *c, char *output)
{
	int	offset;

	if (number)
	{
		offset = recursive_base(number / base_size, base_size, c, output);
		output[offset] = c[number % base_size];
		return (offset + 1);
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base, char *output)
{
	int		base_size;
	long	safe_nbr;

	safe_nbr = nbr;
	if (!valid_base(base, &base_size))
		return ;
	if (safe_nbr == 0)
		output[0] = base[0];
	if (safe_nbr < 0)
	{
		output[0] = '-';
		output++;
		safe_nbr *= -1;
	}
	recursive_base(safe_nbr, base_size, base, output);
}

void	clear_array(char *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		array[i] = 0;
		i++;
	}
}

char	*ft_convert_base(char *number, char *base_from, char *base_to)
{
	int			deca_number;
	int			b_s[2];
	char		*output;

	if (!valid_base(base_from, b_s) || !valid_base(base_to, b_s + 1))
		return (0);
	deca_number = ft_atoi_base(number, base_from);
	output = malloc(40);
	if (output == 0)
		return (0);
	clear_array(output, 40);
	ft_putnbr_base(deca_number, base_to, output);
	return (output);
}

// #include <stdio.h>
// int main()
// {
// 	char* ptr;
// 	printf("===INVALID===\n");
// 	ptr = ft_convert_base("123", "01", "12341");
// 	printf("%p\n", ptr);
// 	ptr = ft_convert_base("0123", "0", "01");
// 	printf("%p\n", ptr);
// 	ptr = ft_convert_base("0123", "0", "01");
// 	printf("%p\n", ptr);
// 	ptr = ft_convert_base("", "01", "01");
// 	printf("%p\n", ptr);
// 	ptr = ft_convert_base("0123", "", "01");
// 	printf("%p\n", ptr);
// 	ptr = ft_convert_base("0123", "01", "");
// 	printf("%p\n", ptr);
// 	ptr = ft_convert_base("0123", "001", "0123");
// 	printf("%p\n", ptr);
// 	ptr = ft_convert_base("0123", "01", "011");
// 	printf("%p\n", ptr);
// 	printf("===DECA===\n");
// 	ptr = ft_convert_base("0", "0123456789", "0123456789");
// 	printf("%s\n", ptr);
// 	free(ptr);
// 	ptr = ft_convert_base("123", "0123456789", "0123456789");
// 	printf("%s\n", ptr);
// 	free(ptr);
// 	ptr = ft_convert_base("30", "0123456789", "0123456789");
// 	printf("%s\n", ptr);
// 	free(ptr);
// 	ptr = ft_convert_base("0123", "0123456789", "0123456789");
// 	printf("%s\n", ptr);
// 	free(ptr);
// 	ptr = ft_convert_base("12300", "0123456789", "0123456789");
// 	printf("%s\n", ptr);
// 	free(ptr);
// 	ptr = ft_convert_base("123+", "0123456789", "0123456789");
// 	printf("%s\n", ptr);
// 	free(ptr);
// 	ptr = ft_convert_base("-123", "0123456789", "0123456789");
// 	printf("%s\n", ptr);
// 	free(ptr);
// 	ptr = ft_convert_base("--123asd", "0123456789", "0123456789");
// 	printf("%s\n", ptr);
// 	free(ptr);
// 	ptr = ft_convert_base("---123d", "0123456789", "0123456789");
// 	printf("%s\n", ptr);
// 	free(ptr);
// 	ptr = ft_convert_base("  ---123", "0123456789", "0123456789");
// 	printf("%s\n", ptr);
// 	free(ptr);
// 	ptr = ft_convert_base("a---123q", "0123456789", "0123456789");
// 	printf("%s\n", ptr);
// 	free(ptr);
// 	ptr = ft_convert_base("2147483647", "0123456789", "01");
// 	printf("%s\n", ptr);
// 	free(ptr);
// 	printf("===BINARY===\n");
// 	ptr = ft_convert_base("7", "0123456789", "01");
// 	printf("%s\n", ptr);
// 	free(ptr);
// 	ptr = ft_convert_base("111", "01", "0123456789");
// 	printf("%s\n", ptr);
// 	free(ptr);
// 	printf("===HEX===\n");
// 	ptr = ft_convert_base("ff", "0123456789abcdef", "0123456789");
// 	printf("%s\n", ptr);
// 	free(ptr);
// 	ptr = ft_convert_base("4096", "0123456789", "0123456789abcdef");
// 	printf("%s\n", ptr);
// 	free(ptr);
// 	printf("===STUPID===\n");
// 	ptr = ft_convert_base("-2147483648", "0123456789",
// "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
// 	printf("%s\n", ptr);
// 	free(ptr);
// 	ptr = ft_convert_base("-2lkCB2",
// "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ",
// "0123456789");
// 	printf("%s\n", ptr);
// 	free(ptr);
// 	ptr = ft_convert_base("2147483648", "0123456789", "01");
// 	printf("%s\n", ptr);
// 	free(ptr);
// }