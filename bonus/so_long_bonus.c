/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <hbouhsis@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:59:32 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/04/25 03:01:47 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/so_long_bonus.h"

int	main(int ac, char **av)
{
	t_vars	*data;

	data = malloc(sizeof (t_vars));
	data->move_count = 0;
	if (ac == 2)
	{
		data->map_arr = parser(av[1], data);
		execute_map(data);
	}
	else
	{
		error_message("Usage : ./so_long < .ber map file>");
	}
}
