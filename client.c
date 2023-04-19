/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:45:06 by apeposhi          #+#    #+#             */
/*   Updated: 2023/04/19 15:49:54 by apeposhi         ###   ########.fr       */
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

	bit = -1;
	i = 0;
	if (!message)
		exit(EXIT_FAILURE);
	while (1)
	{
		bit = -1;
		while (++bit < 8)
		{
			if (message[i] & (0x80 >> bit))
			{
				if (kill(pid, SIGUSR1) == -1)
					exit(1);
			}
			else if (kill(pid, SIGUSR2) == -1)
				exit(1);
			usleep(100);
		}
		if (!message[i])
			break ;
		++i;
	}
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
	send_binary_message(argv[2], pid);
	usleep(120);
}
