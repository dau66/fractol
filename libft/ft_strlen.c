/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:13:54 by ksho              #+#    #+#             */
/*   Updated: 2023/06/07 20:23:25 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

// int main(void)
// {
// 	char *s;
// 	s = calloc((size_t)INT_MAX + 10, sizeof(char));
// 	size_t i = ft_strlen(NULL);
// 	printf("%zu\n",i);
// }