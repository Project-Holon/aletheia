/*
 * function: ZUKAN_DETAIL_GRAPHIC_Delete3dSystem
 * address:  0x021BCF6C
 * packet:   pkt_021BCF18
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZUKAN_DETAIL_GRAPHIC_DeleteCameraAndSystem 0x021BD11C  thumb  ov208

 * BLOCKED.  Unverifiable: ZUKAN_DETAIL_GRAPHIC_DeleteCameraAndSystem resolves only through the `matched` class and layout/matched/ov093 holds BTL_MAIN_ReturnZero in two shards, which aborts every manifest load.
 */
#include "../include/Obj04613.h"


extern void ZUKAN_DETAIL_GRAPHIC_DeleteCameraAndSystem(int *p);

void ZUKAN_DETAIL_GRAPHIC_Delete3dSystem(char *p)
{
    if (((struct Obj04613 *)p)->f10 != 0) {
        ZUKAN_DETAIL_GRAPHIC_DeleteCameraAndSystem((int *)(p + 8));
        ((struct Obj04613 *)p)->f10 = 0;
    }
}

