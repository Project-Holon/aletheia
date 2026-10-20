#ifndef GAME_OV198_B_PLIST_ANM_H
#define GAME_OV198_B_PLIST_ANM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of b_plist_anm.c, prototypes copied from their definitions. */

#include "../types.h"

void B_PLIST_ANM_CopyMonSpriteTiles(char *p,u16 *src);
void B_PLIST_ANM_CopySubSpriteTiles(char *p,u16 *src);
void B_PLIST_ANM_BlitTileRect(u16 *dst, u16 *src, int x, int y, u8 width, u8 height);
void *B_PLIST_ANM_GetTileBuffer(void *p,u32 kind,u32 i,int which);
void B_PLIST_ANM_ApplyTilePalette(u8 *p,void *dst,u8 kind,u8 index,u8 which);
void B_PLIST_ANM_UploadTileBuffer(u8 *p,u8 state,u8 flag,u8 mode);
void B_PLIST_ANM_StartPaletteAnim(u8 *p,unsigned int state);
void B_PLIST_ANM_StepPaletteAnim(u8 *p);
void B_PLIST_ANM_UpdateByMode(u8 *p,u32 mode);
void B_PLIST_ANM_CopyPaletteSlot(unsigned char *p, u32 unused);
u8 B_PLIST_ANM_CountActiveRecords(u8 *p);
void B_PLIST_ANM_UpdateSelectedTile(u8 *p);
void B_PLIST_ANM_CreateTileWindows(u8 *p);
/* END mkheaders: generated region */

#endif
