/*
 * function: WF2DMAP_SCENE_Start
 * address: 0x021D8B0C
 * packet: pkt_ov129_021D8B0C
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_Start 0x0202208C thumb
 *   WF2DMAP_SCENE_LoadActorAssets 0x021D9890 thumb ov129
 *   WF2DMAP_SCENE_SetCellFlags 0x021DA164 thumb ov129
 *   WF2DMAP_SCENE_CreateCellActors 0x021D9AB0 thumb ov129
 *   WF2DMAP_SCENE_LayoutCells 0x021DA1A8 thumb ov129
 *   WF2DMAP_SCENE_CreateCursorActors 0x021D9BEC thumb ov129
 *   WF2DMAP_SCENE_CreateExtraActors 0x021D9D44 thumb ov129
 *   WF2DMAP_SCENE_UpdateCellRects 0x021DA320 thumb ov129
 *   WF2DMAP_SCENE_CreateOam 0x021DA3B8 thumb ov129
 *   WF2DMAP_SCENE_CreateTextOams 0x021DA42C thumb ov129
 *   WF2DMAP_SCENE_CreateWindow 0x021DA524 thumb ov129
 *   WF2DMAP_SCENE_ResetState 0x021D8AF4 thumb ov129
 */
#include "../include/Obj10498.h"

extern void WF2DMAP_SCENE_LoadActorAssets(char *);
extern void WF2DMAP_SCENE_SetCellFlags(void *);
extern void WF2DMAP_SCENE_CreateCellActors(char *);
extern void WF2DMAP_SCENE_LayoutCells(char *,int);
extern void WF2DMAP_SCENE_CreateCursorActors(char *);
extern void WF2DMAP_SCENE_CreateExtraActors(char *);
extern void WF2DMAP_SCENE_UpdateCellRects(char *);
extern void WF2DMAP_SCENE_CreateOam(char *);
typedef unsigned char  u8;
extern void WF2DMAP_SCENE_CreateTextOams(u8 *p);
extern void WF2DMAP_SCENE_CreateWindow(void **p, int a, int b, int c, int d, int e, int f, int g, int h);
extern void WF2DMAP_SCENE_ResetState(char *,int);
extern void WIPE_SYS_Start(void *,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);
int WF2DMAP_SCENE_Start(char *p)  {
    WF2DMAP_SCENE_LoadActorAssets(p);
    WF2DMAP_SCENE_SetCellFlags(p);
    WF2DMAP_SCENE_CreateCellActors(p);
    WF2DMAP_SCENE_LayoutCells(p,0);
    WF2DMAP_SCENE_CreateCursorActors(p);
    WF2DMAP_SCENE_CreateExtraActors(p);
    WF2DMAP_SCENE_UpdateCellRects(p);
    WF2DMAP_SCENE_CreateOam(p);
    WF2DMAP_SCENE_CreateTextOams((u8 *)p);
    WF2DMAP_SCENE_CreateWindow((void **)(p+0x310),((struct Obj10498 *)p)->f328,4,2,19,27,4,((struct Obj10498 *)p)->f314,((struct Obj10498 *)p)->f344);
    WF2DMAP_SCENE_ResetState(p,1);
    WIPE_SYS_Start(0,1,1,0,6,1,50);
    return 0;
}
