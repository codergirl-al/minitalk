/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:24:23 by apeposhi          #+#    #+#             */
/*   Updated: 2023/04/18 22:24:24 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void send_binary_message(char *message, int pid)
{
    if (!message)
        exit(EXIT_FAILURE);

    for (int i = 0; message[i]; i++)
    {
        char letter = message[i];
        for (int j = 7; j >= 0; j--)
        {
            int bit = (letter >> j) & 1;
            if (bit == 1)
            {
                if (kill(pid, SIGUSR1) == -1)
                    exit(1);
            }
            else
            {
                if (kill(pid, SIGUSR2) == -1)
                    exit(1);
            }
            usleep(100);
        }
    }
}

int main(int argc, char *argv[])
{
    int pid;

    if (argc != 3)
    {
        ft_printf("Invalid arguments have been entered.\n");
        exit(EXIT_FAILURE);
    }
    pid = ft_atoi(argv[1]);
    send_binary_message(argv[2], pid);   
}
