/*
 * function: PMS_INPUT_VIEW_TaskSetWordwinCursor
 * address: 0x021BA9B4
 * packet: pkt_ov110_021BA9B4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMS_INPUT_GetCursorCell 0x021BF784 thumb ov110
 *   PMSIV_WORDWIN_SetCursorCell 0x021BFC64 thumb ov110
 *   PMS_INPUT_VIEW_EndTask 0x021B9CBC thumb ov110
 */
#include "../include/Obj00135.h"
#include "../include/Obj13773.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 PMS_INPUT_GetCursorCell(u8 *);
extern void PMSIV_WORDWIN_SetCursorCell(u8 *, u32);
extern void PMS_INPUT_VIEW_EndTask(u8 *);
void PMS_INPUT_VIEW_TaskSetWordwinCursor(void *unused, u8 *p)
{
    u8 *q;
    q = *(u8 * *)&((struct Obj00135 *)p)->f0;
    PMSIV_WORDWIN_SetCursorCell(*(u8 * *)&((struct Obj13773 *)q)->f5C, PMS_INPUT_GetCursorCell(*(u8 * *)&((struct Obj13773 *)q)->f18));
    PMS_INPUT_VIEW_EndTask(p);
}
