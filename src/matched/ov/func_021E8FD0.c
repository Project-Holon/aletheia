/*
 * function: BOX2_SEQ_SetSeqSecond
 * address:  0x021E8FD0
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_MAIN_RestartSeq  0x021DC9B8  thumb  ov170
 *
 * Store the second argument, then re-seat the sub-object.
 */
#include "../include/Obj00000.h"



extern void BOX2_MAIN_RestartSeq(char *);
int BOX2_SEQ_SetSeqSecond(char *p, int a)
{
    *(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0x68) = a;
    BOX2_MAIN_RestartSeq(*(char * *)&((struct Obj00000 *)p)->f2C);
    return 5;
}
