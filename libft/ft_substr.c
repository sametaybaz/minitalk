/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaybaz <aaybaz@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:22:52 by aaybaz            #+#    #+#             */
/*   Updated: 2023/02/02 16:22:54 by aaybaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{	
	char	*str;
	size_t	i;
	size_t	j;

	str = (char *)malloc(len + 1);
	if (!s || !str)
		return (0);
	i = start;
	j = 0;
	while (i < ft_strlen(s) && j < len)
	{
		str[j++] = s[i++];
	}
	str[j] = '\0';
	return (str);
}
