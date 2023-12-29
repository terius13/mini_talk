/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 20:39:53 by ting              #+#    #+#             */
/*   Updated: 2023/12/29 18:03:56 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sendsig(int serverpid, char *str)
{
	int	i;
	int	rshift;
	
	i = 0;
	while (str[i] != '\0')
	{
		rshift = 0;
		while (rshift < 7)
		{
			if ((str[i] >> rshift) | 0)
				kill(serverpid, SIGUSR2);
			else
				kill(serverpid, SIGUSR1);
			rshift++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	serverpid;

	if (argc == 3)
	{
		serverpid = ft_atoi(argv[1]);
		sendsig(serverpid, argv[2]);
	}
	else
		ft_printf("Invalid Inputs");
}
