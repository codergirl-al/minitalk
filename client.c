/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:45:06 by apeposhi          #+#    #+#             */
/*   Updated: 2023/04/20 13:05:50 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	check_signal(int pid, int signal)
{
	if (kill(pid, signal) == -1)
		exit(1);
}

static void	send_binary_message(char *message, int pid)
{
	int	i;
	int	bit;

	i = -1;
	bit = -1;
	if (!message)
		exit(EXIT_FAILURE);
	while (1 && message[++i] != '\0')
	{
		while (++bit < 8)
		{
			if (message[i] & (0x80 >> bit))
			{
				if (kill(pid, SIGUSR1) == -1)
					exit(1);
			}
			else 
			{				
				if (kill(pid, SIGUSR2) == -1)
					exit(1);
			}
			usleep(120);
		}
		if (!message[i])
			break ;
		bit = -1;
	}
	i = -1;
	while (++i < 8) {
		if (kill(pid, SIGUSR2) == -1) {
			exit(1);
		}
	}
}

void	client_sig_handler(int sig_num, siginfo_t *sig_info, void *context)
{
	// if (sig_num == SIGUSR1)
		// ft_printf("Message received.");
}

int	main(int argc, char *argv[])
{
	int	pid;

 	if (argc != 3)
	{
		ft_printf("Invalid arguments have been entered.\n");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("Wrong PID, cannot proceed.\n");
		return (0);
	}
	// ft_printf("My pid:%d\n", getpid());
	send_binary_message(argv[2], pid);
	// sa.sa_sigaction = client_sig_handler;
	// if (sigaction(SIGUSR1, &sa, NULL) != 0)
    // {
    //     write(2, "sigaction error\n", 16);
    //     return (1);
    // }
	usleep(120);
}
