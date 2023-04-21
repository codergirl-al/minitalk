/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:45:06 by apeposhi          #+#    #+#             */
/*   Updated: 2023/04/21 16:13:44 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler(int sig)
{
	if (sig == SIGUSR1)
		write(1, "Message received!\n", 18);
}

static void	send_binary_message(char *message, int pid)
{
	int	i;
	int	bit;

	i = -1;
	bit = -1;
	while (1 && message[++i] != '\0')
	{
		while (++bit < 8)
		{
			if (message[i] & (0x80 >> bit))
				kill(pid, SIGUSR1);
			else			
				kill(pid, SIGUSR2);
			usleep(120);
			signal(SIGUSR1, handler);
		}
		bit = -1;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3)
	{
		write(1, "Invalid arguments have been entered.\n", 37);
		return (EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		write(1, "Wrong PID, cannot proceed.\n", 28);
		return (0);
	}
	send_binary_message(argv[2], pid);
	usleep(120);
	return (0);
}
