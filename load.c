/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:54:23 by thbernar          #+#    #+#             */
/*   Updated: 2019/01/07 14:43:01 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	textures_load(t_app *a)
{
	if (a->p_count <= 0)
		ft_error("Fatal error : invalid file.");
	bmp_loadfile(&a->game_win, "textures/game_win.bmp");
	bmp_loadfile(&a->game_over, "textures/game_over.bmp");
	bmp_loadfile(&a->textures[0], "textures/bigdoor.bmp");
	bmp_loadfile(&a->textures[1], "textures/dude.bmp");
	bmp_loadfile(&a->textures[2], "textures/floor.bmp");
	bmp_loadfile(&a->textures[3], "textures/skulwall.bmp");
	bmp_loadfile(&a->textures[4], "textures/marbface.bmp");
	bmp_loadfile(&a->textures[5], "textures/skulwall2.bmp");
	bmp_loadfile(&a->textures[6], "textures/window.bmp");
	bmp_loadfile(&a->textures[7], "textures/door1.bmp");
	bmp_loadfile(&a->textures[8], "textures/door2.bmp");
	//bmp_loadfile(&a->textures[9], "textures/sky1.bmp");
}

void	sprites_load(t_app *a)
{
	/*
	*** ZOMBIE
	*/
	bmp_loadfile(&a->sprites[0], "sprites/zombie1.bmp");
	//BARREL
	bmp_loadfile(&a->sprites[1], "sprites/ak47.bmp");
	//PILLAR
	bmp_loadfile(&a->sprites[2], "sprites/scope.bmp");
	//FINAL
	bmp_loadfile(&a->sprites[3], "sprites/zombie1.bmp");
	bmp_loadfile(&a->sprites[4], "sprites/ak47.bmp");
	bmp_loadfile(&a->sprites[5], "sprites/ak47fired.bmp");
	bmp_loadfile(&a->sprites[6], "sprites/scope.bmp");
	bmp_loadfile(&a->weapon.img, "sprites/ak47.bmp");
	bmp_loadfile(&a->weapon.img2, "sprites/ak47fired.bmp");
	bmp_loadfile(&a->weapon.scope, "sprites/scope.bmp");
}
