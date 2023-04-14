#include "libft/includes/libft.h"
#include "minitalk.h"
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int pid;

    if (argc != 3 || !ft_validate_client_string(argv[1]))
    {
        ft_printf("Invalid arguments have been entered.\n");
        ft_printf("./client [PID] [STR]\n");
        exit(EXIT_FAILURE);
    }
    
}
