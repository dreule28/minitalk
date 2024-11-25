/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 08:31:51 by dreule            #+#    #+#             */
/*   Updated: 2024/11/25 11:04:02 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minitalk.h"

int	main(int argc, char argv**)
{
	pid_t pid;

	if (argc != 3)
		ft_printf("??? Use 3 arguments!!!");
	exit (1);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		ft_printf("Invalid PID");
	exit (1);
	
}
