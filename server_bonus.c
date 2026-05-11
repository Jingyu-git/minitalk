/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serverbonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingywu <jingywu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 16:07:05 by jingywu           #+#    #+#             */
/*   Updated: 2026/03/09 22:46:16 by jingywu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bhandler(int signal, siginfo_t *info, void *context)
{
	static int				bit_count = 0;
	static unsigned char	c = 0;

	(void)context;
	c <<= 1;
	if (signal == SIGUSR2)
		c |= 1;
	bit_count++;
	if (bit_count == 8)
	{
		if (c == '\0')
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR1);
		}
		else
			write(1, &c, 1);
		bit_count = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID: %d\n", getpid());
	sa.sa_sigaction = bhandler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
