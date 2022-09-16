/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhaddoum <zhaddoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:05:05 by zhaddoum          #+#    #+#             */
/*   Updated: 2022/09/15 21:04:28 by zhaddoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	check_leak(char *str)
{
	if (str[0] != '\0')
		free(str);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	i;
	size_t	k;
	size_t	len;
	char	*ptr;

	i = 0;
	k = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	ptr = (char *) malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[k])
		ptr[i++] = s2[k++];
	ptr[i] = '\0';
	check_leak(s1);
	return (ptr);
}
