/*
 * function: ITEMMENU_ClearMessageWindow
 * address: 0x021BA9AC
 * packet: pkt_ov070_021BA9AC
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 */
#include "../include/Obj20673.h"
extern void BMP_MENUWORK_DrawWindowBorder(void *, unsigned);
void ITEMMENU_ClearMessageWindow(char *p) { BMP_MENUWORK_DrawWindowBorder(((struct Obj20673 *)p)->f4FC, 1); }
