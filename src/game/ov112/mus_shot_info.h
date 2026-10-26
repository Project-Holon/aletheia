#ifndef GAME_OV112_MUS_SHOT_INFO_H
#define GAME_OV112_MUS_SHOT_INFO_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of mus_shot_info.c, prototypes copied from their definitions. */

struct MusicalSave;

#include "../types.h"

void *MUSICAL_SHOT_INFO_Create(void *a, struct MusicalSave *b, u32 c, void *d, u16 heap);
void MUSICAL_SHOT_INFO_Delete(u8 *p);
void MUSICAL_SHOT_INFO_Main(u8 *p);
int MUSICAL_SHOT_INFO_IsFinished(u32 *p);
void MUSICAL_SHOT_INFO_InitGraphics(u8 *p);
void MUSICAL_SHOT_INFO_InitBgLayer(const void *a,u32 b,u32 c);
void MUSICAL_SHOT_INFO_InitWindows(u8 *p);
void MUSICAL_SHOT_INFO_DeleteWindows(u8 *p);
void MUSICAL_SHOT_INFO_PrintMessageStream(u8 *p,u32 index);
void MUSICAL_SHOT_INFO_PrintMessageQueued(u8 *p,u32 index);
void MUSICAL_SHOT_INFO_OpenYesNoMenu(u8 *p);
/* END mkheaders: generated region */

#endif
