#ifndef GAME_OV112_MUS_ITEM_DATA_H
#define GAME_OV112_MUS_ITEM_DATA_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of mus_item_data.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../ov112/mus_item_draw_shared_types.h"

u32 *MUSICAL_MCSS_LoadActorData(int heap);
void MUSICAL_MCSS_FreeActorData(void **p);
u8 *MUSICAL_MCSS_GetElemPtr(u8 *p, int i);
void MUSICAL_MCSS_GetOffset(u8 *elemData, McssOffset *out);
int MUSICAL_MCSS_GetElemSizeFlags(int *p);
int MUSICAL_MCSS_IsModeSupportedA(u16 *p, int mode);
int MUSICAL_MCSS_IsModeSupportedB(u16 *p, int mode);
int MUSICAL_MCSS_IsModeSupportedC(u8 *p, int mode);
int MUSICAL_MCSS_ElemDataHasAltDepth(const unsigned char *elemData);
int MUSICAL_MCSS_ElemDataKeepsFlippedHeight(const unsigned char *elemData);
int MUSICAL_MCSS_GetIndex(unsigned index);
unsigned char MUSICAL_MCSS_GetElemA(void *p, int i);
unsigned char MUSICAL_MCSS_GetElemB(void *p, int i);
unsigned char MUSICAL_MCSS_GetElemC(void *p, int i);
/* END mkheaders: generated region */

#endif
