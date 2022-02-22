/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:30:00 by pfuchs            #+#    #+#             */
/*   Updated: 2022/02/22 02:15:11 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_str(char **s1, char **s2)
{
	char	*temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == 0)
			return (*s1 - *s2);
		s1 += 1;
		s2 += 1;
	}
	return (*s1 - *s2);
}

void	ft_sort_string_tab(char **tab)
{
	int	size;
	int	i;
	int	j;

	i = 0;
	j = 0;
	size = 0;
	while (tab[size] != 0)
		size++;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1)
		{
			if (ft_strcmp(tab[j], tab[j + 1]) > 0)
				ft_swap_str(tab + j, tab + j + 1);
			j++;
		}
		i++;
	}
}
