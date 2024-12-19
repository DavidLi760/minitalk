/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:56:10 by davli             #+#    #+#             */
/*   Updated: 2024/12/19 18:15:53 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_finish = 0;

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char s2, int i)
{
	char	*str;
	int		len;

	if (s2 == '\0')
		g_finish = 1;
	if (!s1)
	{
		s1 = malloc(1);
		len = 2;
		s1[0] = '\0';
	}
	else
		len = ft_strlen(s1) + 2;
	str = malloc(len);
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	if (s2)
		str[i++] = s2;
	str[i] = 0;
	if (s1[0] != '\0')
		free(s1);
	return (str);
}

void	send_back( int signum, siginfo_t *info)
{
	if (signum == SIGUSR1)
		kill(info->si_pid, SIGUSR1);
	if (signum == SIGUSR2)
		kill(info->si_pid, SIGUSR2);
}

void	handler(int signum, siginfo_t *info, void *context)
{
	static int	i = 0;
	static char	c = 0;
	static char	*str;

	(void)context;
	if (signum == SIGUSR2)
		c = c << 1;
	else if (signum == SIGUSR1)
		c = c << 1 | 0b00000001;
	i++;
	if (i == 8)
	{
		str = ft_strjoin(str, c, -1);
		i = 0;
		c = 0;
	}
	if (g_finish == 1)
	{
		ft_printf("%s\n", str);
		free(str);
		str = NULL;
		g_finish = 0;
	}
	send_back(signum, info);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_printf("PID : %d\n", pid);
	while (1)
	{
		sigaction(SIGUSR1, &sa, 0);
		sigaction(SIGUSR2, &sa, 0);
	}
	return (0);
}
