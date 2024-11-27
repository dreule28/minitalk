/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:10:32 by dreule            #+#    #+#             */
/*   Updated: 2024/11/27 10:46:23 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handle_return(int signal_nb)
{
	if (signal_nb == SIGUSR2)
		ft_printf("Signal received!\n");
}

void	send_signal(char *str, pid_t pid)
{
	int	i;
	int	count;

	i = 0;
	while (str[i] != '\0')
	{
		count = 8;
		while (count > 0)
		{
			if (((str[i] >> (count - 1)) & 1) == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
			count--;
		}
		i++;
	}
	count = 0;
	while (count < 8)
	{
		kill(pid, SIGUSR1);
		usleep(50);
		count++;
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;
	pid_t				pid;

	if (argc != 3)
		return (ft_printf("Use 3 arguments or use quotation marks!\n"), 1);
	sa.sa_handler = handle_return;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (ft_printf("What are you doing???\n"), 1);
	pid = ft_atoi(argv[1]);
	if (kill(pid, 0) == -1)
		return (ft_printf("Invalid PID!\n"), 1);
	send_signal(argv[2], pid);
	while (1)
		return (0);
}
