/*
 * function: ZUKAN_DETAIL_GRAPHIC_ApplyCamera
 * address:  0x021BCF2C
 * packet:   pkt_021BCF2C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZUKAN_DETAIL_GRAPHIC_ApplyCameraLookAt 0x021BD12C  thumb  ov208

 * Calls ZUKAN_DETAIL_GRAPHIC_ApplyCameraLookAt on +8 when the word at +0x10 is set.
 */
#include "../include/Obj18203.h"


extern void ZUKAN_DETAIL_GRAPHIC_ApplyCameraLookAt(int *p);

void ZUKAN_DETAIL_GRAPHIC_ApplyCamera(char *p)
{
    if (((struct Obj18203 *)p)->f10 != 0)
        ZUKAN_DETAIL_GRAPHIC_ApplyCameraLookAt((int *)(p + 8));
}

