/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <dmisnich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 17:32:27 by dmisnich          #+#    #+#             */
/*   Updated: 2018/01/26 13:33:03 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		exit_x(void)
{
	system("leaks -quiet fractol");
	exit(0);
}

void	message(char *msg)
{
	ft_putendl(msg);
	exit_x();
}
