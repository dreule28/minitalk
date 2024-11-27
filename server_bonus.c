/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:11:02 by dreule            #+#    #+#             */
/*   Updated: 2024/11/27 10:44:02 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handle_signal(int signal_nb, siginfo_t *info, void *context)
{
	static char	cur_char = 0;
	static int	count = 0;

	(void)context;
	if (signal_nb == SIGUSR1)
		cur_char = (cur_char << 1) | 0;
	else if (signal_nb == SIGUSR2)
		cur_char = (cur_char << 1) | 1;
	count ++;
	if (count == 8)
	{
		if (cur_char == '\0')
		{
			write (1, "\n", 1);
			if (info && info->si_pid > 0)
				kill(info->si_pid, SIGUSR2);
		}
		else
			write (1, &cur_char, 1);
		cur_char = 0;
		count = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	pid = getpid();
	ft_printf("YOUR PID IS: %d.\n", pid);
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| (sigaction(SIGUSR2, &sa, NULL)) == -1)
		return (ft_printf("What are you doing???\n"), 1);
	while (1)
		pause();
	return (0);
}
