/*
 * function: ZUKAN_DETAIL_TOUCHBAR_IsButtonAnimActive
 * address:  0x021BDC2C
 * packet:   pkt_021BDC14
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ZKND_TBAR_IsButtonAnimActive 0x021BD3B4  thumb  ov208

 * Returns the result of ZKND_TBAR_IsButtonAnimActive on two fields while +0x10 is clear, else 0.
 */
#include "../include/Obj09200.h"


extern int ZKND_TBAR_IsButtonAnimActive(void *mgr, int key);

int ZUKAN_DETAIL_TOUCHBAR_IsButtonAnimActive(char *p)
{
    if (((struct Obj09200 *)p)->f10 == 0)
        return ZKND_TBAR_IsButtonAnimActive((void *)(((struct Obj09200 *)p)->f30),
                             *(int *)*(int * *)&((struct Obj09200 *)p)->f7C);
    return 0;
}

