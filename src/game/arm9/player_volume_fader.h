#ifndef GAME_ARM9_PLAYER_VOLUME_FADER_H
#define GAME_ARM9_PLAYER_VOLUME_FADER_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of player_volume_fader.c, prototypes copied from their definitions. */

struct Fader;

#include "../types.h"

struct Fader *PLAYER_VOLUME_FADER_Create(u32 heapId, int v);
void PLAYER_VOLUME_FADER_Delete(void *ptr);
void PLAYER_VOLUME_FADER_Update(struct Fader *s);
void PLAYER_VOLUME_FADER_SetTarget(struct Fader *s, u8 level, u16 frames);
void PLAYER_VOLUME_FADER_SetMute(struct Fader *s, int mute);
void PLAYER_VOLUME_FADER_Init(struct Fader *s);
void PLAYER_VOLUME_FADER_StartFade(struct Fader *s, u8 target, u16 frames);
void PLAYER_VOLUME_FADER_SetLevel(struct Fader *s, u8 level);
void PLAYER_VOLUME_FADER_Tick(struct Fader *s);
u32 PLAYER_VOLUME_FADER_GetLevel(struct Fader *s);
void PLAYER_VOLUME_FADER_Apply(struct Fader *s);
/* END mkheaders: generated region */

#endif
