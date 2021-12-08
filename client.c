/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 13:46:48 by                   #+#    #+#             */
/*   Updated: 2021/12/03 22:01:27 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

int	ft_send_to_srv(int pid, char c)
{
	int	bts;

	bts = 7;
	while (bts != -1)
	{
		if (c & (1 << bts))
		{
			if (kill(pid, SIGUSR1) == -1)
				return (1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				return (1);
		}
		bts--;
		usleep(70);
		usleep(70);
	}
	return (0);
}

void	ft_send_to_func(int pid, char *str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		if (ft_send_to_srv(pid, str[count]))
		{
			write(2, "Oops, enter correct PID\n", 25);
			exit(1);
		}
		count++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;

	(void) argc;
	if (argc != 3)
	{
		write(2, "Invalid number of arguments\n", 29);
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	ft_send_to_func(pid, argv[2]);
}
