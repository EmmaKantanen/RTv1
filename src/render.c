/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:35:43 by ikarjala          #+#    #+#             */
/*   Updated: 2023/01/30 15:53:56 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "render.h"

void	render(t_sdl *sdl)
{
	unsigned int	*px;
	int				x;
	int				y;

	SDL_LockSurface (sdl->surf);
	px = (unsigned int *)(sdl->surf->pixels);
	y = -1;
	while (++y < WIN_H)
	{
		x = -1;
		while (++x < WIN_W)
		{
			*(px++) = to_rgb (raytrace (
						&sdl->ctx, project_ray_from_camera (
							x, y, sdl->ctx.cam)));
		}
	}
	SDL_UnlockSurface (sdl->surf);
	SDL_UpdateWindowSurface (sdl->win);
}
