/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:09:16 by ksho              #+#    #+#             */
/*   Updated: 2023/05/17 14:49:30 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		*str = 0;
		str++;
		i++;
	}
}

// int	main(void)
// {
// 	char str[] = "0123456789";
// 	size_t n = 5;
// 	// memset(str + 2, '*', n);
// 	ft_memset(str + 2, '*', n);
// 	printf("%s\n", str);

// 	return (0);
// }
