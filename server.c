/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:10:40 by dreule            #+#    #+#             */
/*   Updated: 2024/11/27 10:56:40 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signal_nb)
{
	static char	cur_char = 0;
	static int	count = 0;

	if (signal_nb == SIGUSR1)
		cur_char = (cur_char << 1) | 0;
	else if (signal_nb == SIGUSR2)
		cur_char = (cur_char << 1) | 1;
	count ++;
	if (count == 8)
	{
		if (cur_char == '\0')
			write (1, "\n", 1);
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
	sa.sa_handler = handle_signal;
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| (sigaction(SIGUSR2, &sa, NULL)) == -1)
		ft_printf("What are you doing???\n");
	while (1)
		pause();
	return (0);
}
