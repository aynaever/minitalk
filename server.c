#include "minitalk.h"

t_info	g_info;

int	main(void)
{
	printf("The sever PID: %d\n", getpid());
	while (1)
	{
		pause();
		usleep(1);
	}
	return (0);
}
