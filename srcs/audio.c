/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiboitel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 22:24:47 by tiboitel          #+#    #+#             */
/*   Updated: 2016/06/24 22:24:50 by tiboitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Wolf3D/wolf3d.h>

int		wolf3d_audio_init(t_wolf3d *wolf)
{
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 8096) == -1)
		return (-1);
	wolf->music = Mix_LoadWAV(MUSIC_LOOP);
	if (wolf->music == NULL)
		return (-1);
	if (Mix_PlayChannel(-1, wolf->music, -1) == -1)
		return (-1);
	return (1);
}

void	wolf3d_audio_release(t_wolf3d *wolf)
{
	Mix_FreeChunk(wolf->music);
	wolf->music = NULL;
	Mix_CloseAudio();
}
