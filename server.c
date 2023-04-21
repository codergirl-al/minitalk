/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:24:10 by apeposhi          #+#    #+#             */
/*   Updated: 2023/04/21 16:16:15 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int sig_num, siginfo_t *sig_info, void *context)
{
	static char	received_char[9];
	static int	bit_count = 0;
	static char	c = 0;

	if (sig_num == SIGUSR1)
		received_char[bit_count] = '1';
	else if (sig_num == SIGUSR2)
		received_char[bit_count] = '0';
	bit_count++;
	if (bit_count == 8)
	{
		c = ft_convert_binary(received_char);
		write(1, &c, 1);
		kill(sig_info->si_pid, SIGUSR1);
		bit_count = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	write(1, "PID = ", 5);
	ft_putnbr(getpid());
	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR2, &sa, NULL) != 0
		|| sigaction(SIGUSR1, &sa, NULL) != 0)
	{
		write(2, "sigaction error\n", 16);
		return (1);
	}
	while (1)
		pause();
	return (0);
}
