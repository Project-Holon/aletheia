#ifndef GAME_OV127_WF2DMAP_SCRDRAW_H
#define GAME_OV127_WF2DMAP_SCRDRAW_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wf2dmap_scrdraw.c, prototypes copied from their definitions. */

struct Wf2dmapPoint;
struct Wf2dmapBitmapDesc;
typedef struct Wf2dmapPoint Wf2dmapPoint;
typedef struct Wf2dmapBitmapDesc Wf2dmapBitmapDesc;

#include "../types.h"

void WF2DMAP_SCRDRAW_SetPoint(Wf2dmapPoint *p, s16 y, s16 x);
int WF2DMAP_SCRDRAW_GetPointY(const Wf2dmapPoint *p);
int WF2DMAP_SCRDRAW_GetPointX(const Wf2dmapPoint *p);
Wf2dmapBitmapDesc *WF2DMAP_SCRDRAW_CreateBitmapDesc(void *src, u32 count, const u8 *res, u32 heap);
void WF2DMAP_SCRDRAW_DeleteBitmapDesc(u8 *desc);
void WF2DMAP_SCRDRAW_UpdatePosition(char *surface,void *point);
void WF2DMAP_SCRDRAW_LoadPalette(void *unused, u32 id, u8 *res);
void WF2DMAP_SCRDRAW_SetScroll(char *surface,int x,int y);
void WF2DMAP_SCRDRAW_DrawTilesClipped(void *surface,int layer,unsigned int charRes,s16 x,s16 y);
void WF2DMAP_SCRDRAW_DrawTilesWrapped(void *surface, u8 layer, u8 x, u8 y, u8 w, u8 h, void *tiles, u8 sx, u8 sy, int width, int height);
int WF2DMAP_SCRDRAW_GetMode(unsigned int width, unsigned int height);
char *WF2DMAP_SCRDRAW_GetTileSource(char *tiles, u8 x, u8 y, unsigned mode, int w, int h, u16 *out);
/* END mkheaders: generated region */

#endif
