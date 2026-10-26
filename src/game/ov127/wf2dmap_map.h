#ifndef GAME_OV127_WF2DMAP_MAP_H
#define GAME_OV127_WF2DMAP_MAP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wf2dmap_map.c, prototypes copied from their definitions. */

struct Wf2dmapMapGrid;
union Wf2dmapCell;
typedef struct Wf2dmapMapGrid Wf2dmapMapGrid;
typedef union Wf2dmapCell Wf2dmapCell;

#include "../types.h"

int WF2DMAP_MAP_IsEmpty(char *p);
Wf2dmapMapGrid *WF2DMAP_MAP_CreateGrid(u32 w,u32 h,u32 heap);
void WF2DMAP_MAP_DeleteGrid(u8 *p);
u16 WF2DMAP_MAP_GetWidth(u16 *p);
u16 WF2DMAP_MAP_GetHeight(u16 *p);
void WF2DMAP_MAP_CopyEntries(u8 *p,void *out);
Wf2dmapCell WF2DMAP_MAP_GetCell(u8 *p, u32 x, u32 y);
int WF2DMAP_MAP_IsCellBlocked(u8 *p, u16 x, u16 y);
u32 WF2DMAP_MAP_GetCellValue(u8 *p, u16 x, u16 y);
/* END mkheaders: generated region */

#endif
