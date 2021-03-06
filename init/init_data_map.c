/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <vronchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 18:05:53 by vronchin          #+#    #+#             */
/*   Updated: 2020/08/20 18:06:03 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	check_wrong_character(int y, int x, t_data *data)
{
	if (data->map[y][x] != ' ' && data->map[y][x] != '0' && \
		data->map[y][x] != '1' && data->map[y][x] != '2' &&\
		data->map[y][x] != 'N' && data->map[y][x] != 'S' &&\
		data->map[y][x] != 'E' && data->map[y][x] != 'W')
		ft_display_error(data, "Wrong character somewhere!");
}

void	check_close_map(int y, int x, t_data *data)
{
	if ((data->map[y][x] != ' ' && data->map[y][x] != '1')\
		&& (y == 0 || y == data->map_h \
		|| x == 0 || x == data->map_w))
		ft_display_error(data, "Close the map(1)!");
	if (data->map[y][x] == ' ' && (!(data->map[y][x + 1] == ' ' ||\
		data->map[y][x + 1] == '1') && !(data->map[y + 1][x] == ' ' || \
		data->map[y + 1][x] == '1')))
		ft_display_error(data, "Close the map!(2)");
}

void	check_position_missing(t_data *data)
{
	if (data->posx == 0)
		ft_display_error(data, "Position missing");
}

void	init_data_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->map_h)
	{
		while (data->map[y][x])
		{
			check_wrong_character(y, x, data);
			if (data->map[y][x] == '2')
				data->nbsprite += 1;
			check_close_map(y, x, data);
			if (data->map[y][x] == 'N' || data->map[y][x] == 'S' ||\
			data->map[y][x] == 'E' || data->map[y][x] == 'W')
			{
				init_position(data->map[y][x], x, y, data);
				data->map[y][x] = '0';
			}
			x++;
		}
		x = 0;
		y++;
	}
	check_position_missing(data);
}
