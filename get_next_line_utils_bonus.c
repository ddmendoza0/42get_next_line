/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendoza <dmendoza@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:12:05 by dmendoza          #+#    #+#             */
/*   Updated: 2025/01/08 14:04:36 by dmendoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = -1;
	while (s[++i])
		;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == s[i])
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	t_len;
	char	*s_join;
	int		i;
	int		j;

	t_len = ft_strlen(s1) + ft_strlen(s2);
	s_join = (char *)malloc((t_len + 1) * sizeof(char));
	if (!s_join)
		return (NULL);
	i = -1;
	while (s1[++i])
		s_join[i] = s1[i];
	j = -1;
	while (s2[++j])
		s_join[i++] = s2[j];
	s_join[t_len] = '\0';
	return (s_join);
}

static void	*ft_bzero(void *s, size_t n)
{
	char			*ptr;
	size_t			i;

	ptr = (char *)s;
	i = -1;
	while (++i < n)
		ptr[i] = '\0';
	return (ptr);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	t_size;
	void	*ptr;

	if (size == 0 || nmemb == 0)
		return (malloc(0));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	t_size = nmemb * size;
	ptr = (void *)malloc(t_size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, t_size);
	return (ptr);
}
