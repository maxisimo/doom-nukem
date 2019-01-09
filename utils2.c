/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 16:09:25 by lchappon          #+#    #+#             */
/*   Updated: 2019/01/08 19:23:28 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int		ft_close(t_app *app)
{
	free(app->map);
	system("killall afplay 2&>/dev/null >/dev/null");
	exit(0);
	return (0);
}

void	ft_error(char *s)
{
	ft_putstr(s);
	system("killall afplay 2&>/dev/null >/dev/null");
	exit(-1);
}

void	ft_free_strsplit(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_init_tex_fc(t_app *a)
{
	if (a->side == 0 && a->ray.dir.x > 0)
	{
		a->floor.x = a->mapx;
		a->floor.y = a->mapy + a->wallx;
	}
	else if (a->side == 0 && a->ray.dir.x < 0)
	{
		a->floor.x = a->mapx + 1.0;
		a->floor.y = a->mapy + a->wallx;
	}
	else if (a->side == 1 && a->ray.dir.y > 0)
	{
		a->floor.x = a->mapx + a->wallx;
		a->floor.y = a->mapy;
	}
	else
	{
		a->floor.x = a->mapx + a->wallx;
		a->floor.y = a->mapy + 1.0;
	}
	if (a->end < 0)
		a->end = WIN_H;
}

void	ft_info(t_app *a)
{
	if (((a->map[(int)a->pos.x][(int)(a->pos.y + a->cam.dir.x)] == HDOOR &&
			fabs(a->cam.dir.x) > fabs(a->cam.dir.y)) ||
			(a->map[(int)(a->pos.x + a->cam.dir.y)][(int)a->pos.y] == VDOOR &&
			fabs(a->cam.dir.x) < fabs(a->cam.dir.y))) &&
			a->move.v <= 1)
		mlx_string_put(a->mlx, a->win, WIN_WD, WIN_HD, 0xFFFFFF, OPEN);
	if (((a->map[(int)a->pos.x][(int)(a->pos.y + a->cam.dir.x)] == HDOOR_O &&
			fabs(a->cam.dir.x) > fabs(a->cam.dir.y) &&
			a->map[(int)a->pos.x][(int)a->pos.y] != HDOOR_O) ||
			(a->map[(int)(a->pos.x + a->cam.dir.y)][(int)a->pos.y] == VDOOR_O &&
			fabs(a->cam.dir.x) < fabs(a->cam.dir.y) &&
			a->map[(int)a->pos.x][(int)a->pos.y] != VDOOR_O)) &&
			a->move.v <= 1)
		mlx_string_put(a->mlx, a->win, WIN_WD, WIN_HD, 0xFFFFFF, CLOSE);
	if ((a->map[(int)a->pos.x][(int)(a->pos.y + a->cam.dir.x)] == 13 ||
			a->map[(int)(a->pos.x + a->cam.dir.y)][(int)a->pos.y] == 13) &&
			a->move.v <= 1)
		mlx_string_put(a->mlx, a->win, WIN_WD, WIN_HD, 0xFFFFFF, END);
	mlx_string_put(a->mlx, a->win, 10, WIN_H - 30, 0xFFFFFF,
			ft_strjoin(ft_itoa(a->life), " HEALTH POINTS"));
	mlx_string_put(a->mlx, a->win, 10, WIN_H - 50, 0xFFFFFF,
			ft_strjoin(ft_itoa(a->ammo), " AMMUNITIONS"));
	mlx_string_put(a->mlx, a->win, 10, WIN_H - 70, 0xFFFFFF,
			ft_strjoin(ft_itoa(a->enemies_count2), " ENEMIES"));
}
