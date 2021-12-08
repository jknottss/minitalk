/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 14:10:14 by                   #+#    #+#             */
/*   Updated: 2021/12/01 18:22:22 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

int		ft_atoi(char *str);
void	ft_putnumber(int nb);
void	ft_putchar(int c);
void	ft_decode(int signal, siginfo_t *info, void *context);
void	ft_send_to_func(int pid, char *str);
int		ft_send_to_srv(int pid, char c);
#endif
