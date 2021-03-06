/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:57:59 by dmisnich          #+#    #+#             */
/*   Updated: 2017/11/10 13:58:02 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	unsigned int	i;
	char			res;

	i = 1;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * -1;
	}
	while ((nb / i) > 9)
		i = i * 10;
	while (i > 0)
	{
		res = (nb / i) + '0';
		nb = nb % i;
		i = i / 10;
		write(1, &res, 1);
	}
}
