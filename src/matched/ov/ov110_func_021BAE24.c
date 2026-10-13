/*
 * function: PMS_INPUT_VIEW_UpdateEditFocus
 * address: 0x021BAE24
 * packet: pkt_ov110_021BAE24
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero padding
 * symbols:
 *   PMSIV_EDIT_SetCursorsVisible 0x021BC704 thumb ov110
 *   PMS_INPUT_GetCancelSelected 0x021BF71C thumb ov110
 *   PMSIV_MENU_SetActiveEntry 0x021BCF7C thumb ov110
 */
#include "../include/Obj02459.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void PMSIV_EDIT_SetCursorsVisible(u8 *p, u32 flag);
extern u16 PMS_INPUT_GetCancelSelected(u8 *);
extern void PMSIV_MENU_SetActiveEntry(u8 *p, int n, int v);
void PMS_INPUT_VIEW_UpdateEditFocus(u8 *p, u8 *a1, void *a2) {
    if(**(u32 * *)&((struct Obj02459 *)p)->f78==1) {
        PMSIV_EDIT_SetCursorsVisible(*(u8 * *)&((struct Obj02459 *)p)->f54,0);
        PMSIV_MENU_SetActiveEntry(*(u8 * *)&((struct Obj02459 *)p)->f64,(u8)PMS_INPUT_GetCancelSelected(*(u8 * *)&((struct Obj02459 *)p)->f18),0);
    } else if(p[0x74]==1) {
        PMSIV_EDIT_SetCursorsVisible(*(u8 * *)&((struct Obj02459 *)p)->f54,0);
        PMSIV_MENU_SetActiveEntry(*(u8 * *)&((struct Obj02459 *)p)->f64,(u8)PMS_INPUT_GetCancelSelected(*(u8 * *)&((struct Obj02459 *)p)->f18),1);
    } else {
        PMSIV_EDIT_SetCursorsVisible(*(u8 * *)&((struct Obj02459 *)p)->f54,1);
        PMSIV_MENU_SetActiveEntry(*(u8 * *)&((struct Obj02459 *)p)->f64,(u8)PMS_INPUT_GetCancelSelected(*(u8 * *)&((struct Obj02459 *)p)->f18),0);
    }
}
