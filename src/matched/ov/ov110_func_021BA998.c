/*
 * function: PMS_INPUT_VIEW_TaskSetCategoryPosition
 * address: 0x021BA998
 * packet: pkt_ov110_021BA998
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMS_INPUT_GetCursorPos 0x021BF724 thumb ov110
 *   PMSIV_CATEGORY_MoveCursor 0x021BB6A0 thumb ov110
 *   PMS_INPUT_VIEW_EndTask 0x021B9CBC thumb ov110
 */
#include "../include/Obj00135.h"
#include "../include/Obj13772.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 PMS_INPUT_GetCursorPos(u8 *);
extern void PMSIV_CATEGORY_MoveCursor(u8 *, u32);
extern void PMS_INPUT_VIEW_EndTask(u8 *);
void PMS_INPUT_VIEW_TaskSetCategoryPosition(void *unused, u8 *p)
{
    u8 *q;
    q = *(u8 * *)&((struct Obj00135 *)p)->f0;
    PMSIV_CATEGORY_MoveCursor(*(u8 * *)&((struct Obj13772 *)q)->f58, PMS_INPUT_GetCursorPos(*(u8 * *)&((struct Obj13772 *)q)->f18));
    PMS_INPUT_VIEW_EndTask(p);
}
