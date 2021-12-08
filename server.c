/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:42:53 by                   #+#    #+#             */
/*   Updated: 2021/12/03 21:52:24 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_decode(int signal, siginfo_t *info, void *context)
{
	static char	new_ch;
	static int	bts = 7;
	static int	pid;

	(void) context;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		write(1, "\n", 1);
		bts = 7;
	}
	if (signal == SIGUSR1)
		new_ch |= (1 << bts);
	if (signal == SIGUSR2)
		new_ch &= ~(1 << bts);
	bts--;
	if (bts == -1)
	{
		write(1, &new_ch, 1);
		bts = 7;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sig;

	(void) argc;
	(void) argv;
	if (argc != 1)
		write(1, "You don't need arguments for server\n", 36);
	pid = getpid();
	write(1, "This is a server's PID:", 23);
	ft_putnumber(pid);
	sig.sa_sigaction = ft_decode;
	sigaction(SIGUSR1, &sig, 0);
	sigaction(SIGUSR2, &sig, 0);
	while (1)
		pause();
}
