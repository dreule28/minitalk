/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 08:31:51 by dreule            #+#    #+#             */
/*   Updated: 2024/11/26 08:21:07 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
			usleep(500);
			count--;
		}
		i++;
		count = 0;
	}
	while (count < 8)
	{
		kill(pid, SIGUSR1);
		usleep(500);
		count++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;

	if (argc != 3)
		return (ft_printf("Use 3 arguments or use quotation marks!\n"), 1);
	pid = ft_atoi(argv[1]);
	if (kill(pid, 0) == -1)
		return (ft_printf("Invalid PID!\n"), 1);
	send_signal(argv[2], pid);
}
