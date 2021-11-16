#include "minitalk.h"

char	*g_out;

void	checknull(void)
{
	int	i;
	int	j;

	i = ft_strlen(g_out) - 1;
	j = 8;
	while (j > 0)
	{
		if (g_out[i] == '1')
			return ;
		i--;
		j--;
	}
}

void	printchar(void)
{
	int	bin;
	int	rem;
	int	out;
	int	pow;

	bin = ft_atoi(g_out);
	ft_bzero(g_out, 8);
	pow = 1;
	out = 0;
	while (bin > 0)
	{
		rem = bin % 10;
		out += rem * pow;
		bin /= 10;
		pow *= 2;
	}
	ft_putchar_fd(out, 1);
}

void	my_handler(int signum)
{
	char	in[2];

	if (signum == SIGUSR1)
		in[0] = '1';
	if (signum == SIGUSR2)
		in[0] = '0';
	in[1] = 0;
	g_out = ft_strjoin(g_out, in);
	if (ft_strlen(g_out) == 8 && in[0] == '0')
		checknull();
	if (ft_strlen(g_out) == 8)
		printchar();
}

int	main(void)
{
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, my_handler);
	signal(SIGUSR2, my_handler);
	while (true)
		pause();
}
