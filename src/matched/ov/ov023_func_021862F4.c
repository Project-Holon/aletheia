/*
 * function: OEKAKI_ClearMessageWindow
 * address: 0x021862F4
 * packet: pkt_ov023_021862F4
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 */
#include "../include/Obj20365.h"
extern void BMP_MENUWORK_DrawWindowBorder(void *, unsigned int);
void OEKAKI_ClearMessageWindow(char *p)
{
    BMP_MENUWORK_DrawWindowBorder(((struct Obj20365 *)p)->f11C, 0);
}
