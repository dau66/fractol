/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksho <ksho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:29:02 by ksho              #+#    #+#             */
/*   Updated: 2023/06/12 20:06:19 by ksho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (str == NULL && len == 0)
		return (NULL);
	if (*to_find == '\0')
		return ((char *)str);
	while (str[i] != '\0' && len != 0)
	{
		while (str[i + j] == to_find[j] && to_find[j] != '\0' && (i + j) < len)
			j++;
		if (to_find[j] == '\0')
			return ((char *)&str[i]);
		else
		{
			i++;
			j = 0;
		}
	}
	return (NULL);
}

// int	main(void)
// {
// 	char *a, *b;

// 	a = "libft-test-tokyo";
// 	printf("%s\n", ft_strnstr(NULL, "1", 1));
// 	printf("%s\n", strnstr(NULL, "1", 1));
// }