/*
 * function: ZUKAN_DETAIL_TOUCHBAR_SetButtonAnimSeq
 * address:  0x021BDC14
 * packet:   pkt_021BDC14
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZKND_TBAR_SetButtonAnimSeqOnce 0x021BD3A4  thumb  ov208

 * Calls ZKND_TBAR_SetButtonAnimSeqOnce with two fields and the second argument while +0x10 is clear.
 */
#include "../include/Obj02345.h"


extern void ZKND_TBAR_SetButtonAnimSeqOnce(int a, int b, int c);

void ZUKAN_DETAIL_TOUCHBAR_SetButtonAnimSeq(char *p, int b)
{
    if (((struct Obj02345 *)p)->f10 == 0)
        ZKND_TBAR_SetButtonAnimSeqOnce(*(int *)&((struct Obj02345 *)p)->f30, *(int *)*(int * *)&((struct Obj02345 *)p)->f7C, b);
}

