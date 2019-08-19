/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 09:43:03 by bpace             #+#    #+#             */
/*   Updated: 2019/07/28 06:29:57 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ans;
	size_t	i;

	i = 0;
	ans = malloc(sizeof(char) * len + 1);
	if (ans == NULL || !s)
		return (NULL);
	while (i < len)
		ans[i++] = s[start++];
	ans[i] = '\0';
	return (ans);
}
