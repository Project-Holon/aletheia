/*
 * function: PMS_INPUT_VIEW_TaskSetEditCursor
 * address: 0x021BA958
 * packet: pkt_ov110_021BA958
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMS_INPUT_GetWordSlot 0x021BF714 thumb ov110
 *   PMSIV_EDIT_PlaceCursorAtSlot 0x021BC72C thumb ov110
 *   PMS_INPUT_VIEW_EndTask 0x021B9CBC thumb ov110
 */
#include "../include/Obj00135.h"
#include "../include/Obj13770.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 PMS_INPUT_GetWordSlot(u8 *);
extern void PMSIV_EDIT_PlaceCursorAtSlot(char *p, int i);
extern void PMS_INPUT_VIEW_EndTask(u8 *);
void PMS_INPUT_VIEW_TaskSetEditCursor(void *unused, u8 *p)
{
    u8 *q;
    q = *(u8 * *)&((struct Obj00135 *)p)->f0;
    PMSIV_EDIT_PlaceCursorAtSlot((char *)(*(u8 * *)&((struct Obj13770 *)q)->f54), PMS_INPUT_GetWordSlot(*(u8 * *)&((struct Obj13770 *)q)->f18));
    PMS_INPUT_VIEW_EndTask(p);
}
