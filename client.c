/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:24:23 by apeposhi          #+#    #+#             */
/*   Updated: 2023/04/18 23:40:44 by apeposhi         ###   ########.fr       */
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
	char	letter;
	int		bit;
	int		i;
	int		j;

	if (!message)
		exit(EXIT_FAILURE);
	i = -1;
	j = 8;
	while (message[++i])
	{
		letter = message[i];
		while (j-- >= 0)
		{
			bit = (letter >> j) & 1;
			if (bit == 1)
				check_signal(pid, SIGUSR1);
			else
				check_signal(pid, SIGUSR1);
			usleep(100);
		}
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
	send_binary_message(argv[2], pid);
}
