/*
 * function: WF2DMAP_OBJDRAW_ConfigureSprite
 * address:  0x021C5664
 * packet:   pkt_021C5664
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WIFI_2DCHAR_SetupCells  0x021C4044  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02184.h"

typedef unsigned char  u8;
extern void WIFI_2DCHAR_SetupCells(u8 *p, int a, int b, int c, int d);

void WF2DMAP_OBJDRAW_ConfigureSprite(char *p, int a, int b)
{
    WIFI_2DCHAR_SetupCells(((struct Obj02184 *)p)->f0, ((struct Obj02184 *)p)->fB, a, 0, b);
}
