/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 19:29:03 by                   #+#    #+#             */
/*   Updated: 2021/12/01 18:00:22 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

static int	ft_start(char *str)
{
	int	count;

	count = 0;
	while ((str[count] >= 9 && str[count] <= 13 ) || str[count] == ' ')
		count++;
	return (count);
}

int	ft_atoi(char *str)
{
	int		res;
	int		count;
	int		sign;
	char	*s;

	res = 0;
	sign = 1;
	s = str;
	count = ft_start(s);
	if (s[count] == '-' || s[count] == '+')
	{
		if (s[count] == '-')
			sign = -1;
		count++;
	}
	while (s[count] > 47 && s[count] < 58)
	{
		res = (res * 10) + (s[count] - '0');
		count++;
	}
	return (res * sign);
}

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putnumber(int nb)
{
	if (nb > 9)
		ft_putnumber(nb / 10);
	ft_putchar((nb % 10) + '0');
}
