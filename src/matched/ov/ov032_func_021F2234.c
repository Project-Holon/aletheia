/*
 * function: BEACON_VIEW_Create
 * address:  0x021F2234
 * packet:   pkt_ov032_021F2234
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BEACON_VIEW_Create 0x021F2234 thumb
 *   func_02030734 0x02030734 arm
 *   d_021F36A0 0x021F36A0 data ov032 a1
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAMESYSTEM_GetFieldMap 0x0201210C thumb
 *   FIELDMAP_GetVReq 0x02188E30 thumb ov021
 *   func_020490F4 0x020490F4 arm
 *   BEACON_VIEW_InitWorkFromSave 0x021F27D4 thumb ov032
 *   BEACON_VIEW_CreateSubSystems 0x021F2908 thumb ov032
 *   BEACON_VIEW_InitBackgrounds 0x021F2A8C thumb ov032
 *   BEACON_VIEW_CreateTaskMenuRes 0x021F2C1C thumb ov032
 *   BEACON_VIEW_LoadGraphics 0x021F2D20 thumb ov032
 *   BEACON_VIEW_CreateActors 0x021F2F44 thumb ov032
 *   BEACON_VIEW_CreateWindows 0x021F3058 thumb ov032
 *   BEACON_VIEW_InitList 0x021EFEC0 thumb ov032
 *   BEACON_VIEW_SetFadeState 0x021F0208 thumb ov032
 */
#include "../include/Obj00007.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern char d_021F36A0[];
struct Ctx;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u32 FIELDMAP_GetVReq(u8 *p);
extern void *func_020490F4(u32 id, u32 heap);
extern void BEACON_VIEW_InitWorkFromSave(u8 *p);
extern void BEACON_VIEW_CreateSubSystems(char *p);
extern void BEACON_VIEW_InitBackgrounds(u8 *p, void *h);
extern void BEACON_VIEW_CreateTaskMenuRes(char *p);
extern void BEACON_VIEW_LoadGraphics(char *p, void *a);
extern void BEACON_VIEW_CreateActors(char *p, void *a);
extern void BEACON_VIEW_CreateWindows(char *p);
extern void BEACON_VIEW_InitList(u8 *o);
extern void BEACON_VIEW_SetFadeState(u8 *p, int flag);

char *BEACON_VIEW_Create(u32 a0, u32 a1)
{
    char *p;
    void *v;

    p = func_02030734(0x70, 0x3d0, 1, d_021F36A0, 0x8d);
    ((struct Obj00007 *)p)->f0 = a0;
    ((struct Obj00007 *)p)->f4 = (u32)GAMESYSTEM_GetGameData((const struct Ctx *)a0);
    ((struct Obj00007 *)p)->f8 = v = GAMESYSTEM_GetFieldMap((void *)a0);
    ((struct Obj00007 *)p)->f10 = FIELDMAP_GetVReq(v);
    ((struct Obj00007 *)p)->fC = a1;
    ((struct Obj00007 *)p)->f98 = 0x70;
    ((struct Obj00007 *)p)->f94 = 0x15;
    ((struct Obj00007 *)p)->f96 = 0x8070;
    ((struct Obj00007 *)p)->f9C = func_020490F4(0xad, ((struct Obj00007 *)p)->f98);
    BEACON_VIEW_InitWorkFromSave((u8 *)p);
    BEACON_VIEW_CreateSubSystems(p);
    BEACON_VIEW_InitBackgrounds((u8 *)p, ((struct Obj00007 *)p)->f9C);
    BEACON_VIEW_CreateTaskMenuRes(p);
    BEACON_VIEW_LoadGraphics(p, ((struct Obj00007 *)p)->f9C);
    BEACON_VIEW_CreateActors(p, ((struct Obj00007 *)p)->f9C);
    BEACON_VIEW_CreateWindows(p);
    ((struct Obj00007 *)p)->f7A = 1;
    BEACON_VIEW_InitList((u8 *)p);
    ((struct Obj00007 *)p)->f7A = 0;
    *(u32 *)&((struct Obj00007 *)p)->f60 = 0;
    BEACON_VIEW_SetFadeState((u8 *)p, 1);
    return p;
}
