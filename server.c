#include "minitalk.h"

char	*g_out;

void	printchar(siginfo_t *info)
{
	int	bin;
	int	rem;
	int	out;
	int	pow;

	bin = ft_atoi(g_out);
	ft_bzero(g_out, 9);
	pow = 1;
	out = 0;
	while (bin > 0)
	{
		rem = bin % 10;
		out += rem * pow;
		bin /= 10;
		pow *= 2;
	}
	bin = 0;
	if (out == 0)
	{
		kill(info->si_pid, SIGUSR1);
		ft_putchar_fd('\n', 1);
	}	
	ft_putchar_fd(out, 1);
}

void	handle(int signum, siginfo_t *info, void *context)
{
	char	in[2];

	if (signum == SIGUSR1)
		in[0] = '1';
	if (signum == SIGUSR2)
		in[0] = '0';
	in[1] = 0;
	g_out = ft_strjoin(g_out, in);
	if (!g_out)
		exit(0);
	if (ft_strlen(g_out) == 8)
		printchar(info);
}

int	main(void)
{
	struct sigaction	sa;

	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (true)
		pause();
}
