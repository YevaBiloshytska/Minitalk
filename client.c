/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybiloshy <ybiloshy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 19:44:37 by ybiloshy          #+#    #+#             */
/*   Updated: 2025/01/06 07:00:02 by ybiloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <signal.h>

static int	g_ack_received = 0;

void	ack_handler(int signum)
{
	(void)signum;
	g_ack_received = 1;
}

void	send_signal_and_wait(int pid, int signal)
{
	g_ack_received = 0;
	usleep(50);
	kill(pid, signal);
	while (!g_ack_received)
		usleep(50);
}

void	send_signal(int pid, char *message)
{
	int	i;
	int	letter;

	letter = 0;
	while (message[letter])
	{
		i = 0;
		while (i < 8)
		{
			g_ack_received = 0;
			if (((unsigned char)(message[letter] >> (7 - i)) & 1) == 0)
				kill(pid, SIGUSR1);
			else if (((unsigned char)(message[letter] >> (7 - i)) & 1) == 1)
				kill(pid, SIGUSR2);
			while (!g_ack_received)
				usleep(50);
			i++;
		}
		letter++;
	}
	i = 0;
	while (i++ < 8)
		send_signal_and_wait(pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	int		server_id;

	if (argc == 3)
	{
		server_id = ft_atoi(argv[1]);
		signal(SIGUSR1, ack_handler);//0
		send_signal(server_id, argv[2]);
	}
	else
		ft_printf("Error.\nEnter as follow: ./client <PID> <MESSAGE>");
}
