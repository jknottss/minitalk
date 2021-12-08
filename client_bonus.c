/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 13:46:48 by                   #+#    #+#             */
/*   Updated: 2021/12/07 19:15:00 by jknotts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

int	g_flag = 1;

int	ft_send_to_srv(int pid, char c)
{
	int	bts;

	bts = 7;
	while (bts != -1)
	{
		if (g_flag)
		{
			g_flag = 0;
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
		}
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
	ft_send_to_srv(pid, 0);
}

void	ft_confirm(int signal, siginfo_t *info, void *context)
{
	(void) info;
	(void) context;
	usleep(300);
	if (signal == SIGUSR1)
	{
		write(1, "signal_ok\n", 10);
		g_flag = 1;
	}
	if (signal == SIGUSR2)
	{
		write(1, "signal_exit\n", 13);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sig;

	(void) argc;
	if (argc != 3)
	{
		write(2, "Invalid number of arguments\n", 29);
		exit(1);
	}
	sig.sa_sigaction = ft_confirm;
	sigaction(SIGUSR1, &sig, 0);
	sigaction(SIGUSR2, &sig, 0);
	pid = ft_atoi(argv[1]);
	ft_send_to_func(pid, argv[2]);
	while (1)
		pause();
}
