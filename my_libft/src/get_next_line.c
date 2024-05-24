/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicifer <alicifer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:19:57 by alicifer          #+#    #+#             */
/*   Updated: 2024/02/12 13:24:21 by alicifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*read_and_join(int fd, char *s_buffer)
{
	char	*joined_buffer;
	char	*aux;
	int		n_bytes_read;

	joined_buffer = ft_calloc ((BUFFER_SIZE + 1), sizeof(char));
	if (!joined_buffer)
		return (NULL);
	n_bytes_read = 1;
	while (!ft_strchrbool(joined_buffer, '\n') && n_bytes_read > 0)
	{
		n_bytes_read = read(fd, joined_buffer, BUFFER_SIZE);
		if (n_bytes_read < 0)
		{
			free (s_buffer);
			s_buffer = NULL;
			return (NULL);
		}
		aux = s_buffer;
		s_buffer = ft_strjoin_gnl(aux, joined_buffer, n_bytes_read);
	}
	free (joined_buffer);
	if (ft_strlengnl(s_buffer) == 0)
		return (free(s_buffer), (NULL));
	return (s_buffer);
}

char	*clean_line(char *s_buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (s_buffer[i] != '\n' && s_buffer[i] != '\0')
		i++;
	line = ft_calloc(i + 1 + (s_buffer[i] == '\n'), sizeof(char));
	if (!line)
		return (NULL);
	j = 0;
	while (s_buffer[j] != '\n' && s_buffer[j] != '\0')
	{
		line[j] = s_buffer[j];
		j++;
	}
	if (s_buffer[j] == '\n')
	{
		line[j++] = '\n';
	}
	line[j] = '\0';
	return (line);
}

char	*clean_nextline(char *s_buffer)
{
	int		i;
	int		j;
	char	*nextline;

	i = 0;
	while (s_buffer[i] != '\n' && s_buffer[i] != '\0')
		i++;
	if (ft_strlengnl(s_buffer) - i == 0)
	{
		free (s_buffer);
		s_buffer = NULL;
		return (NULL);
	}
	nextline = ft_calloc((ft_strlengnl(s_buffer) - i + 1), sizeof(char));
	if (!nextline)
		return (NULL);
	j = 0;
	i++;
	while (s_buffer[i] != '\0')
		nextline[j++] = s_buffer[i++];
	free(s_buffer);
	s_buffer = NULL;
	return (nextline);
}

char	*get_next_line(int fd)
{
	static char	*s_buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		free (s_buffer);
		s_buffer = NULL;
		return (NULL);
	}
	s_buffer = read_and_join(fd, s_buffer);
	if (!s_buffer)
		return (NULL);
	line = clean_line(s_buffer);
	s_buffer = clean_nextline(s_buffer);
	return (line);
}
