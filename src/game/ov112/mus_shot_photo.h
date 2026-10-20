#ifndef GAME_OV112_MUS_SHOT_PHOTO_H
#define GAME_OV112_MUS_SHOT_PHOTO_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of mus_shot_photo.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../ov112/musical_shot_types.h"

u8 *MUSICAL_SHOT_SYS_CreateScene(u8 *src, u16 heap);
void MUSICAL_SHOT_SYS_DeleteScene(u8 *scene);
void MUSICAL_SHOT_SYS_DrawScene(u8 *scene);
void MUSICAL_SHOT_SYS_Init3D(char *p);
void MUSICAL_SHOT_SYS_LoadBg(const void *a,u32 b,u32 c);
void MUSICAL_SHOT_SYS_Exit3D(u8 *scene);
void MUSICAL_SHOT_SYS_InitActors(ShotScene *p);
u32 MUSICAL_SHOT_SYS_GetActorSlotX(void *p,u32 i,u16 c);
void MUSICAL_SHOT_SYS_DrawCaption(u8 *scene);
void MUSICAL_SHOT_SYS_NoOp(u8 *unused);
/* END mkheaders: generated region */

#endif
