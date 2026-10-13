/*
 * function: PMS_INPUT_VIEW_SetMenuItemMode
 * address: 0x021BAC30
 * packet: pkt_ov110_021BAC30
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMSIV_MENU_SelectItem 0x021BCF18 thumb ov110
 */
#include "../include/Obj22339.h"
typedef unsigned char u8;
extern void PMSIV_MENU_SelectItem(void *,int);
void PMS_INPUT_VIEW_SetMenuItemMode(u8 *p,int mode)
{
    PMSIV_MENU_SelectItem(((struct Obj22339 *)p)->f64,mode);
}
