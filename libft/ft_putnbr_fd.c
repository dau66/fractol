/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:02:51 by ksho              #+#    #+#             */
/*   Updated: 2023/06/08 18:27:23 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_put_setting(int nb, int fd)
{
	if (nb < 10)
	{
		nb += '0';
		write(fd, &nb, 1);
	}
	else
	{
		ft_put_setting(nb / 10, fd);
		ft_put_setting(nb % 10, fd);
	}
}

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb < 0)
	{
		write(fd, "-", 1);
		if (nb == -2147483648)
		{
			write(fd, "2", 1);
			nb += 2000000000;
		}
		nb *= -1;
	}
	ft_put_setting(nb, fd);
}

// int main(void)
// {
// 	int a;

// 	a = -1000;
// 	ft_putnbr_fd(a, 1);
// }