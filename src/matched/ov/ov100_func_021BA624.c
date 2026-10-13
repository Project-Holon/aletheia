/*
 * function: IRCBATTLEMATCH_InitWindowSystem
 * address: 0x021BA624
 * packet: pkt_ov100_021BA624
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0203F8F4 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   GF_FONT_ResetTextColor 0x0201DD60 thumb
 */
#include "../include/Obj13711.h"
typedef unsigned short u16;
extern void func_0203F8F4(u16),BMP_WIN_Init(u16);
extern void GF_FONT_ResetTextColor(void);
void IRCBATTLEMATCH_InitWindowSystem(unsigned a)
{
 func_0203F8F4(((struct Obj13711 *)a)->f278);
 BMP_WIN_Init(((struct Obj13711 *)a)->f278);
 GF_FONT_ResetTextColor();
}
