/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:54:28 by ting              #+#    #+#             */
/*   Updated: 2024/01/01 15:55:56 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	sendsig(int serverpid, char *str)
{
	int	i;
	int	rshift;
	int	character;

	i = 0;
	while (str[i] != '\0')
	{
		character = (unsigned char)str[i];
		rshift = 7;
		while (rshift >= 0)
		{
			if ((character >> rshift) & 1)
				kill(serverpid, SIGUSR2);
			else
				kill(serverpid, SIGUSR1);
			rshift--;
			usleep(300);
		}
		i++;
	}
}

void	receivesig(int signum)
{
	if (signum == SIGUSR2)
		ft_printf("Character has been received by server\n");
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					serverpid;

	sa.sa_handler = receivesig;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR2, &sa, NULL);
	if (argc == 3)
	{
		serverpid = ft_atoi(argv[1]);
		sendsig(serverpid, argv[2]);
	}
	else
		ft_printf("INVALID INPUTS");
	while (1)
	{
		pause();
	}
}
