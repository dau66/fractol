/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_hand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:32:14 by ksho              #+#    #+#             */
/*   Updated: 2023/10/23 18:18:37 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	window_free(t_windows **param)
{
	(*param)->mlx = NULL;
	(*param)->win = NULL;
}

void	error_output(void)
{
	ft_printf("input error!\n");
	exit(EXIT_FAILURE);
}
