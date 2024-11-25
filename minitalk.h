/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:21:10 by dreule            #+#    #+#             */
/*   Updated: 2024/11/25 16:17:37 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

void	send_signal(char *str, pid_t pid);
int		client_main(int argc, char *argv[]);
void	handle_signal(int signal_nb);
int		server_main(void);

#endif