/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 17:20:49 by thbernar          #+#    #+#             */
/*   Updated: 2017/11/20 11:36:32 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isprime(int nb)
{
	int i;

	i = 3;
	if (nb % 2 == 0)
		return (0);
	while (i <= nb / 2)
	{
		if (nb % i == 0)
			return (0);
		i = i + 2;
	}
	return (1);
}
