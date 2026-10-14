/*
 * function: ZUKAN_DETAIL_GRAPHIC_EndDraw3d
 * address:  0x021BCF3C
 * packet:   pkt_021BCF2C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZUKAN_DETAIL_GRAPHIC_EndDraw 0x021BD140  thumb  ov208

 * Calls ZUKAN_DETAIL_GRAPHIC_EndDraw on +8 when the word at +0x10 is set.
 */
#include "../include/Obj18204.h"


extern void ZUKAN_DETAIL_GRAPHIC_EndDraw(char *);

void ZUKAN_DETAIL_GRAPHIC_EndDraw3d(char *p)
{
    if (((struct Obj18204 *)p)->f10 != 0)
        ZUKAN_DETAIL_GRAPHIC_EndDraw(p + 8);
}

