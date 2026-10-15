/*
 * function: GTSNEGO_DISP_SetCursorState
 * address: 0x021D69F4
 * packet: pkt_ov120_021D69F4
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gGtsnegoEntryTable 0x021D8B70 data a1
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   APP_TASKMENU_WIN_SetActive 0x02028218 thumb
 */
#include "../include/Obj06437.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
typedef struct Entry { u8 code, x, y, other; } Entry;
typedef struct Vec { s16 x, y; } Vec;
extern const Entry gGtsnegoEntryTable[];
typedef unsigned short u16;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void APP_TASKMENU_WIN_SetActive(struct Obj *obj, u32 a);
void GTSNEGO_DISP_SetCursorState(u8 *p, void *q, u32 n)
{
    Vec v;
    switch (n) {
    case 9:
        CLACT_SetActorDrawEnable(((struct Obj06437 *)p)->f134, 0);
        return;
    case 5:
        CLACT_SetActorDrawEnable(((struct Obj06437 *)p)->f134, 0);
        if (q) APP_TASKMENU_WIN_SetActive(q, 1);
        return;
    case 2: case 3: case 4: case 6: case 7: case 8:
        if (q) APP_TASKMENU_WIN_SetActive(q, 0);
        break;
    case 0: case 1: default: break;
    }
    v.x = gGtsnegoEntryTable[n].x;
    v.y = gGtsnegoEntryTable[n].y;
    CLACT_AddActorSurfacePos(((struct Obj06437 *)p)->f134, (const struct Vec2 *)(&v), 1);
    CLACT_SetActorAnimSeq(((struct Obj06437 *)p)->f134, gGtsnegoEntryTable[n].code);
    CLACT_SetActorDrawEnable(((struct Obj06437 *)p)->f134, 1);
}
