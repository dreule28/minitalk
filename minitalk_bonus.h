/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:11:47 by dreule            #+#    #+#             */
/*   Updated: 2024/11/27 10:54:54 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "libft/libft.h"
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

void	send_signal(char *str, pid_t pid);
void	handle_signal(int signal_nb, siginfo_t *info, void *context);
void	handle_return(int signal_nb);

#endif