/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:28:00 by tel-mouh          #+#    #+#             */
/*   Updated: 2021/12/23 06:42:26 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
	// int fd = open("files/41_with_nl", O_CREAT | O_RDWR, 0777);
	// int t = -1;


	
	// while(++t < 5)
	// {
		
		printf("%d", (*get_next_line(0))-48);
		
	// }

	
	
	

	return 0;
}
