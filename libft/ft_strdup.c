/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:39:11 by osabir            #+#    #+#             */
/*   Updated: 2022/11/14 13:44:36 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;

	str = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!str)
		return (NULL);
	return (ft_memcpy(str, (char *)s1, ft_strlen(s1) + 1));
}
