#include "minitalk.h"

void	sendsig(char *str, int pid)
{
	int		i;
	int		j;

	j = 0;
	while (str[j])
	{
		i = 7;
		while (i >= 0)
		{
			if ((str[j] >> i) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(200);
			i--;
		}
		j++;
	}
}

void	complete(int sig)
{
	(void)sig;
	ft_putstr_fd("\x1b[32mMessage Sent!\033[0m\n", 1);
	exit(0);
}

int	main(int argc, char *argv[])
{
	int		pid;
	int		i;

	if (argc > 3 | argc < 3)
		exit(0);
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, complete);
	sendsig(argv[2], pid);
	i = 0;
	while (i++ < 8)
	{
		kill(pid, SIGUSR2);
		usleep(200);
	}	
	while (true)
		pause();
}
