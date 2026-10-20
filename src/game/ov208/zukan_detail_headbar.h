#ifndef GAME_OV208_ZUKAN_DETAIL_HEADBAR_H
#define GAME_OV208_ZUKAN_DETAIL_HEADBAR_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of zukan_detail_headbar.c, prototypes copied from their definitions. */

struct Ov208Icon;

#include "../types.h"

struct Ov208Icon *ZUKAN_DETAIL_HEADBAR_Create(u16 heap,unsigned arg);
void ZUKAN_DETAIL_HEADBAR_Delete(struct Ov208Icon *m);
void ZUKAN_DETAIL_HEADBAR_Update(struct Ov208Icon *p);
void ZUKAN_DETAIL_HEADBAR_SetIconKind(struct Ov208Icon *p, int kind);
int ZUKAN_DETAIL_HEADBAR_GetIconKind(struct Ov208Icon *p);
void ZUKAN_DETAIL_HEADBAR_SetIconSpecies(struct Ov208Icon *p);
void ZUKAN_DETAIL_HEADBAR_SetIconForm(struct Ov208Icon *p);
void ZUKAN_DETAIL_HEADBAR_NoOp(void *p);
void ZUKAN_DETAIL_HEADBAR_CreateWindows(struct Ov208Icon *g);
void ZUKAN_DETAIL_HEADBAR_DeleteWindows(struct Ov208Icon *p);
void ZUKAN_DETAIL_HEADBAR_DrawIcon(struct Ov208Icon *p);
void ZUKAN_DETAIL_HEADBAR_ClearIcon();
void ZUKAN_DETAIL_HEADBAR_FlushIcon(struct Ov208Icon *p);
/* END mkheaders: generated region */

#endif
