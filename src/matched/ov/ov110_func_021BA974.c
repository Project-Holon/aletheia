/*
 * function: PMS_INPUT_VIEW_TaskSetMenuActive
 * address: 0x021BA974
 * packet: pkt_ov110_021BA974
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero alignment padding.
 * symbols:
 *   PMS_INPUT_GetCancelSelected 0x021BF71C thumb ov110
 *   PMSIV_MENU_SetActiveEntry 0x021BCF7C thumb ov110
 *   PMS_INPUT_VIEW_EndTask 0x021B9CBC thumb ov110
 */
#include "../include/Obj00135.h"
#include "../include/Obj13771.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 PMS_INPUT_GetCancelSelected(u8 *);
extern void PMSIV_MENU_SetActiveEntry(u8 *p, int n, int v);
extern void PMS_INPUT_VIEW_EndTask(u8 *);
void PMS_INPUT_VIEW_TaskSetMenuActive(void *unused, u8 *p)
{
    u8 *q;
    q = *(u8 * *)&((struct Obj00135 *)p)->f0;
    PMSIV_MENU_SetActiveEntry(*(u8 * *)&((struct Obj13771 *)q)->f64, (u8)PMS_INPUT_GetCancelSelected(*(u8 * *)&((struct Obj13771 *)q)->f18), 1);
    PMS_INPUT_VIEW_EndTask(p);
}
