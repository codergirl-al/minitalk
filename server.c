#include "minitalk.h"

void sig_handler(int sig_num, siginfo_t* sig_info, void* context)
{
    static char received_char;
    static int  bit_count;
    char        c;

    if (sig_num == SIGUSR1)
        received_char |= (1 << bit_count);
    else if (sig_num == SIGUSR2)
        received_char &= -(1 << bit_count);
    bit_count++;
    if (bit_count == 8)
    {
        c = ft_convert_binary(&received_char);
        if (c == '\0')
        {
            write (1, "\n", 1);
            kill(sig_info->si_pid, SIGUSR1);
        }
        else
            write(1, &c, 1);
    }
    bit_count = 0;
    received_char = 0;
}

int main(void) {
    pid_t pid;
    struct sigaction sa;

    // Set up signal handler
    sa.sa_sigaction = &sig_handler;
    sa.sa_flags = SA_SIGINFO;
	ft_printf("PID: %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}