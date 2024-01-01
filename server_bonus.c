/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:54:43 by ting              #+#    #+#             */
/*   Updated: 2024/01/01 15:49:17 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	sighandler(int sig, siginfo_t *info, void *ucontent)
{
	static int	character = 0;
	static int	i = 0;

	if (sig == SIGUSR1)
		character = character << 1;
	else if (sig == SIGUSR2)
		character = (character << 1) | 1;
	i++;
	if (i == 8)
	{
		ft_printf("%c", character);
		i = 0;
		character = 0;
		kill(info->si_pid, SIGUSR2);
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = sighandler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("THE SERVER_BONUS PID IS: %d\n", getpid());
	while (1)
	{
		pause();
	}
}
