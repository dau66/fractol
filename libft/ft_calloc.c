/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:23:37 by ksho              #+#    #+#             */
/*   Updated: 2023/07/12 20:21:47 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memory;

	if (nmemb == 0 || size == 0)
	{
		memory = malloc(1);
		if (!memory)
			return (NULL);
		ft_bzero(memory, 1);
		return (memory);
	}
	if (nmemb > 0 && SIZE_MAX / nmemb < size)
		return (NULL);
	memory = malloc(nmemb * size);
	if (memory == NULL)
		return (NULL);
	ft_bzero(memory, (nmemb * size));
	return (memory);
}

// int	main(void)
// {
// 	int *ptr, *p;
// 	int i;

// 	/* 500個のintサイズのメモリを確保 */
// 	ptr = (int *)calloc((size_t)SIZE_MAX / 10 + (size_t)100, 10);
// 	if (ptr == NULL)
// 	{
// 		printf("メモリが確保できません\n");
// 		exit(EXIT_FAILURE);
// 	}

// 	p = ptr;
// 	for (i = 0; i < 10; i++)
// 	{
// 		*p = i;
// 		printf("%d ", *p);
// 		p++;
// 	}

// 	/* メモリの開放 */
// 	free(ptr);

// 	return (0);
// }