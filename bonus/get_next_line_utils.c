/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:10:15 by asauafth          #+#    #+#             */
/*   Updated: 2025/10/26 23:53:26 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	while (i < (nmemb * size))
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

int	ft_strlen_gnl(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	if ((char)c == '\0')
	{
		return ((char *)(s + i));
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*new_string;

	if (!s1)
		return (ft_strdup(s2));
	i = 0;
	new_string = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_string || !s1 || !s2)
		return (NULL);
	while (s1[i] != '\0')
	{
		new_string[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		new_string[i++] = s2[j];
		j++;
	}
	new_string[i] = '\0';
	return (new_string);
}

char	*ft_strdup(const char *s)
{
	char	*d;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	d = (char *)malloc(sizeof(char) * (len + 1));
	if (!d)
		return (NULL);
	while (s[i] != '\0')
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}
