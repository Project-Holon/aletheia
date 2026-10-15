/*
 * function: WF2DMAP_SCENE_ProcessPending
 * address: 0x021D9760
 * packet: pkt_ov129_021D9760
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   WF2DMAP_SCENE_SetSlot 0x021D8950 thumb ov129
 *   WF2DMAP_SCENE_SetCellFlags 0x021DA164 thumb ov129
 *   WF2DMAP_SCENE_LayoutCells 0x021DA1A8 thumb ov129
 *   WF2DMAP_SCENE_ResetState 0x021D8AF4 thumb ov129
 *   WF2DMAP_SCENE_MoveCursor 0x021D9E60 thumb ov129
 *   WF2DMAP_SCENE_ClearPending 0x021D97B8 thumb ov129
 * Extent ends with two bytes of zero alignment padding.
 */
#include "../include/Obj00361.h"

extern void WF2DMAP_SCENE_SetSlot(char *,int);
extern void WF2DMAP_SCENE_SetCellFlags(void *);
extern void WF2DMAP_SCENE_LayoutCells(char *,int);
extern void WF2DMAP_SCENE_ResetState(char *,int);
typedef unsigned char  u8;
extern void WF2DMAP_SCENE_MoveCursor(u8 *p, int n);
extern void WF2DMAP_SCENE_ClearPending(char *);
void WF2DMAP_SCENE_ProcessPending(char *p)  {
    switch(((struct Obj00361 *)p)->f31C)  {
        case 0: break;
        case 1: WF2DMAP_SCENE_SetSlot(p,((struct Obj00361 *)p)->f320);
        WF2DMAP_SCENE_SetCellFlags(p);
        WF2DMAP_SCENE_LayoutCells(p,1);
        WF2DMAP_SCENE_ResetState(p,2);
        ((struct Obj00361 *)p)->f31C=255;
        break;
        case 2: WF2DMAP_SCENE_MoveCursor((u8 *)p,((struct Obj00361 *)p)->f320);
        WF2DMAP_SCENE_ClearPending(p);
        break;
        case 255: break;
    }
}
