/*
 * function: PMS_INPUT_VIEW_TaskActivateEdit
 * address: 0x021BA1A0
 * packet: pkt_ov110_021BA1A0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero alignment padding.
 * symbols:
 *   PMSIV_EDIT_Redraw 0x021BC23C thumb ov110
 *   PMS_INPUT_GetWordSlot 0x021BF714 thumb ov110
 *   PMSIV_EDIT_PlaceCursorAtSlot 0x021BC72C thumb ov110
 *   PMSIV_MENU_UpdateItemHighlight 0x021BCCA8 thumb ov110
 *   PMSIV_MENU_UpdateEntryPalette 0x021BCD44 thumb ov110
 *   PMS_INPUT_VIEW_EndTask 0x021B9CBC thumb ov110
 */
#include "../include/Obj00135.h"
#include "../include/Obj06381.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void PMSIV_EDIT_Redraw(void *);
extern u16 PMS_INPUT_GetWordSlot(u8 *);
extern void PMSIV_EDIT_PlaceCursorAtSlot(char *p, int i);
extern void PMSIV_MENU_UpdateItemHighlight(void *);
extern void PMSIV_MENU_UpdateEntryPalette(u8 *p);
extern void PMS_INPUT_VIEW_EndTask(u8 *);
void PMS_INPUT_VIEW_TaskActivateEdit(void *unused, u8 *p)
{
    u8 *q;
    q = *(u8 * *)&((struct Obj00135 *)p)->f0;
    q[0x74] = 0;
    PMSIV_EDIT_Redraw(((struct Obj06381 *)q)->f54);
    PMSIV_EDIT_PlaceCursorAtSlot((char *)(*(u8 * *)&((struct Obj06381 *)q)->f54), PMS_INPUT_GetWordSlot(*(u8 * *)&((struct Obj00135 *)p)->f4));
    PMSIV_MENU_UpdateItemHighlight(((struct Obj06381 *)q)->f64);
    PMSIV_MENU_UpdateEntryPalette(((struct Obj06381 *)q)->f64);
    PMS_INPUT_VIEW_EndTask(p);
}
