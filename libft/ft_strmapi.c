/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:09:52 by ksho              #+#    #+#             */
/*   Updated: 2023/06/12 14:12:47 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*newstr;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	newstr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (newstr == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		newstr[i] = f(i, s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

// int	main(void)
// {
// 	const char *s1 = "abcdefgh";
// 	char (*a)(unsigned int, char);
// 	a = doubleChar;

// 	char *s = ft_strmapi(s1, a);
// 	printf("%s\n", s);
// 	free(s);
// 	return (0);
// }