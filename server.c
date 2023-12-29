/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 20:39:32 by ting              #+#    #+#             */
/*   Updated: 2023/12/29 22:00:39 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <unistd.h>

void	sig_handler(int sig)
{
	write(1, "lol\n", 4);
}

int	main(void)
{
	struct	sigaction sa;
	sa.sa_handler = sig_handler;
	sa.sa_flags= 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("THE SERVER PID IS: %d\n", getpid());

	while(1)
	{
		pause();
	}
}
