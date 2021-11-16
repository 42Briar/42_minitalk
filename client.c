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
			usleep(300);
			i--;
		}
		j++;
	}
	i = -1;
	while (++i < 8)
		kill(pid, SIGUSR2);
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc > 3 | argc < 3)
		exit(0);
	pid = ft_atoi(argv[1]);
	sendsig(argv[2], pid);
}
