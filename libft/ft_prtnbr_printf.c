/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prtnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ting <ting@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:37:43 by ting              #+#    #+#             */
/*   Updated: 2023/12/20 23:11:20 by ting             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int	ft_prtnbr_printf(int nbr)
{
	long int	n;
	int		count;

	count = 0;
	n = nbr;
	if (n < 0)
	{
		count += ft_prtchar_printf('-');
		n = -n;
	}
	if (n > 9)
	{
		count += ft_prtnbr_printf(n / 10);
	}
	n = n % 10 + '0';
	count += ft_prtchar_printf(n);
	return (count);
}
