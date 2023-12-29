/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 20:39:32 by ting              #+#    #+#             */
/*   Updated: 2023/12/29 14:45:08 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <unistd.h>

int	main(void)
{
	int	n = 42;

	write(1, &n, 1);
	ft_printf("THE SERVER PID IS: %d", getpid());
}
