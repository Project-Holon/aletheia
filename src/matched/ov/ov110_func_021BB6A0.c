/*
 * function: PMSIV_CATEGORY_MoveCursor
 * address: 0x021BB6A0
 * packet: pkt_ov110_021BB6A0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: ordered if/else chain, not switch dispatch; template word is 0x012C0190.
 * symbols:
 *   sPmsivCategoryCursorOrigin 0x021C38D0 data ov110 a2
 *   PMS_INPUT_GetBrowseMode 0x021BF6DC thumb ov110
 *   PMS_INPUT_VIEW_GetMenu 0x021BAC3C thumb ov110
 *   PMSIV_MENU_SetActiveEntry 0x021BCF7C thumb ov110
 *   PMSI_SEARCH_GetKeyPosition 0x021BB224 thumb ov110
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   _u32_div_f 0x0209C2B0 arm
 */
#include "../include/Obj04445.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef struct { s16 x, y; } Vec2;
extern const Vec2 sPmsivCategoryCursorOrigin;
extern u8 PMS_INPUT_GetBrowseMode(u8 *);
extern unsigned PMS_INPUT_VIEW_GetMenu(u8 *);
extern void PMSIV_MENU_SetActiveEntry(u8 *, int, int);
extern void PMSI_SEARCH_GetKeyPosition(unsigned, int *, int *);
typedef unsigned int   u32;
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
void PMSIV_CATEGORY_MoveCursor(u8 *p, unsigned index)
{
    Vec2 pos;
    int x, y;
    int state;
    u8 *q;
    pos = sPmsivCategoryCursorOrigin;
    if (PMS_INPUT_GetBrowseMode(*(u8 * *)&((struct Obj04445 *)p)->f4) == 0 && index != 254) {
        pos.x = 48 + 80 * (index % 3U);
        pos.y = 64 + 24 * (index / 3U);
        state = 4;
    } else {
        q = (u8 *)PMS_INPUT_VIEW_GetMenu(*(u8 * *)&((struct Obj04445 *)p)->f0);
        state = 16;
        if (index == 252) {
            if (**(int * *)&((struct Obj04445 *)p)->f5C == 0) PMSIV_MENU_SetActiveEntry(q, 0, 1);
            else PMSIV_MENU_SetActiveEntry(q, 0, 0);
        } else if (index == 253) {
            if (**(int * *)&((struct Obj04445 *)p)->f5C == 0) PMSIV_MENU_SetActiveEntry(q, 1, 1);
            else PMSIV_MENU_SetActiveEntry(q, 0, 0);
        } else if (index == 254) {
            if (**(int * *)&((struct Obj04445 *)p)->f5C == 0) PMSIV_MENU_SetActiveEntry(q, 2, 1);
            else PMSIV_MENU_SetActiveEntry(q, 0, 0);
        } else {
            PMSIV_MENU_SetActiveEntry(q, 0, 0);
            PMSI_SEARCH_GetKeyPosition(index, &x, &y);
            pos.x = x + 18;
            pos.y = y + 56;
            state = 6;
        }
    }
    CLACT_AddActorSurfacePos(((struct Obj04445 *)p)->f54, (const struct Vec2 *)(&pos), 0);
    CLACT_SetActorAnimSeq(((struct Obj04445 *)p)->f54, state);
}
