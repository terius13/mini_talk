/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 20:39:32 by ting              #+#    #+#             */
/*   Updated: 2024/01/01 16:00:05 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <unistd.h>

void	sig_handler(int sig)
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
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = sig_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("THE SERVER PID IS: %d\n", getpid());
	while (1)
	{
		pause();
	}
}
