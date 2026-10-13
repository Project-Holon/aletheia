/*
 * function: PMS_INPUT_VIEW_TaskLeaveMenu
 * address: 0x021BA290
 * packet: pkt_ov110_021BA290
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   PMS_INPUT_GetCancelSelected 0x021BF71C thumb ov110
 *   PMSIV_MENU_SetActiveEntry 0x021BCF7C thumb ov110
 *   PMSIV_EDIT_NoopB 0x021BC728 thumb ov110
 *   PMSIV_EDIT_SetCursorsVisible 0x021BC704 thumb ov110
 *   PMS_INPUT_GetWordSlot 0x021BF714 thumb ov110
 *   PMSIV_EDIT_PlaceCursorAtSlot 0x021BC72C thumb ov110
 *   PMS_INPUT_VIEW_EndTask 0x021B9CBC thumb ov110
 */
#include "../include/Obj00135.h"
#include "../include/Obj05287.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern u16 PMS_INPUT_GetCancelSelected(u8 *);
extern void PMSIV_MENU_SetActiveEntry(u8 *p, int n, int v);
extern void PMSIV_EDIT_NoopB(u8 *);
typedef unsigned int   u32;
extern void PMSIV_EDIT_SetCursorsVisible(u8 *p, u32 flag);
extern u16 PMS_INPUT_GetWordSlot(u8 *);
extern void PMSIV_EDIT_PlaceCursorAtSlot(char *p, int i);
extern void PMS_INPUT_VIEW_EndTask(u8 *);
void PMS_INPUT_VIEW_TaskLeaveMenu(int unused, u8 *p) {
    u8 *q = *(u8 * *)&((struct Obj00135 *)p)->f0;
    q[0x74] = 0;
    PMSIV_MENU_SetActiveEntry(*(u8 * *)&((struct Obj05287 *)q)->f64, (u8)PMS_INPUT_GetCancelSelected(*(u8 * *)&((struct Obj05287 *)q)->f18), 0);
    PMSIV_EDIT_NoopB(*(u8 * *)&((struct Obj05287 *)q)->f54);
    PMSIV_EDIT_SetCursorsVisible(*(u8 * *)&((struct Obj05287 *)q)->f54, 1);
    PMSIV_EDIT_PlaceCursorAtSlot((char *)(*(u8 * *)&((struct Obj05287 *)q)->f54), PMS_INPUT_GetWordSlot(*(u8 * *)&((struct Obj00135 *)p)->f4));
    PMS_INPUT_VIEW_EndTask(p);
}
