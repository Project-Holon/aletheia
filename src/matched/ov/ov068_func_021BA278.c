/*
 * function: OPTION_MENU_PrintText
 * address: 0x021BA278
 * packet: pkt_ov068_021BA278
 * region: ov068
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   OPTION_MENU_PrintTextFromBank 0x021BA28C thumb ov068
 */
#include "../include/Obj00884.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void OPTION_MENU_PrintTextFromBank(u8 *, u32, u32, u32, u32);
void OPTION_MENU_PrintText(u8 *p, u32 a, u32 b, u32 c)
{
    OPTION_MENU_PrintTextFromBank(p, ((struct Obj00884 *)p)->f0, a, b, c);
}
