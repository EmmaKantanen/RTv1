/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarjala <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:15:40 by ikarjala          #+#    #+#             */
/*   Updated: 2022/11/19 17:58:57 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

// NOTE: if we find no further use for this header file, just move s_rgb to scene.h
// or back to rtv1.h instead

typedef struct s_rgb
{
	float	r;
	float	g;
	float	b;
}	t_rgb;

enum e_sdl_init_flags {
	esdl_dev = SDL_INIT_VIDEO
};

#endif
