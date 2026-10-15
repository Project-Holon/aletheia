/*
 * function: WF2DMAP_OBJDRAW_AddActor
 * address: 0x021C5680
 * packet: pkt_ov127_021C5680
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WF2DMAP_OBJDRAW_AllocActor 0x021C58C8 thumb ov127
 *   WF2DMAP_OBJ_GetSlot 0x021C49A4 thumb ov127
 *   WF2DMAP_OBJDRAW_GetDepth 0x021C5878 thumb ov127
 *   WIFI_2DCHAR_SpawnActor 0x021C40BC thumb ov127
 *   WF2DMAP_OBJDRAW_UpdateActor 0x021C574C thumb ov127
 */
#include "../include/Obj00328.h"
#include "../include/Obj14031.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern u8 *WF2DMAP_OBJDRAW_AllocActor(void *);
extern int WF2DMAP_OBJ_GetSlot(u8 *p, unsigned int i);
extern int WF2DMAP_OBJDRAW_GetDepth(int, int);
extern void *WIFI_2DCHAR_SpawnActor(void *, s16 *, int, u32);
extern void WF2DMAP_OBJDRAW_UpdateActor(u8 *p);
u8 *WF2DMAP_OBJDRAW_AddActor(u8 *p, void *q, int n, u32 heap)
{
    u8 *o = WF2DMAP_OBJDRAW_AllocActor(p);
    s16 pos[4];
    ((struct Obj00328 *)o)->f8 = WF2DMAP_OBJ_GetSlot(q, 5);
    ((struct Obj00328 *)o)->fA = WF2DMAP_OBJ_GetSlot(q, 6);
    ((struct Obj00328 *)o)->fC = WF2DMAP_OBJ_GetSlot(q, 4);
    ((struct Obj00328 *)o)->f0 = q;
    o[18] = n;
    o[19] = 1;
    ((struct Obj00328 *)o)->fE = 0;
    ((struct Obj00328 *)o)->f10 = 0;
    pos[0] = WF2DMAP_OBJ_GetSlot(q, 0);
    pos[1] = WF2DMAP_OBJ_GetSlot(q, 1);
    pos[2] = WF2DMAP_OBJDRAW_GetDepth(pos[1], o[18]);
    pos[3] = p[10];
    ((struct Obj00328 *)o)->f4 = WIFI_2DCHAR_SpawnActor(((struct Obj14031 *)p)->f0, pos, WF2DMAP_OBJ_GetSlot(q, 7), heap);
    WF2DMAP_OBJDRAW_UpdateActor(o);
    return o;
}
