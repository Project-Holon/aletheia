/*
 * function: PMS_INPUT_VIEW_TaskPickMenuItemDecided
 * address: 0x021BA220
 * packet: pkt_ov110_021BA220
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMSIV_EDIT_SetCursorsVisible 0x021BC704 thumb ov110
 *   PMSIV_EDIT_NoopA 0x021BC724 thumb ov110
 *   PMS_INPUT_GetCancelSelected 0x021BF71C thumb ov110
 *   PMSIV_MENU_SetActiveEntry 0x021BCF7C thumb ov110
 *   PMS_INPUT_VIEW_EndTask 0x021B9CBC thumb ov110
 */
#include "../include/Obj00135.h"
#include "../include/Obj06382.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void PMSIV_EDIT_SetCursorsVisible(u8 *p, u32 flag);
extern void PMSIV_EDIT_NoopA(u8 *);
extern u16 PMS_INPUT_GetCancelSelected(u8 *);
extern void PMSIV_MENU_SetActiveEntry(u8 *p, int n, int v);
extern void PMS_INPUT_VIEW_EndTask(u8 *);
void PMS_INPUT_VIEW_TaskPickMenuItemDecided(void *unused, u8 *p)
{
    u8 *q;
    q = *(u8 * *)&((struct Obj00135 *)p)->f0;
    q[0x74] = 1;
    PMSIV_EDIT_SetCursorsVisible(*(u8 * *)&((struct Obj06382 *)q)->f54, 0);
    PMSIV_EDIT_NoopA(*(u8 * *)&((struct Obj06382 *)q)->f54);
    PMSIV_MENU_SetActiveEntry(*(u8 * *)&((struct Obj06382 *)q)->f64, (u8)PMS_INPUT_GetCancelSelected(*(u8 * *)&((struct Obj06382 *)q)->f18), 1);
    PMS_INPUT_VIEW_EndTask(p);
}
