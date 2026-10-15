/*
 * function: BOX2_MAIN_StepMover
 * address:  0x021DE120
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_MAIN_AdvanceMover  0x021DDEFC  thumb  ov170
 *
 * Program the two 4-short descriptor pairs (0x24, arg2, arg1, 1)
 *   of the p+0x2c+0x60 block and publish each.
 */
#include "../include/Obj00000.h"


extern void BOX2_MAIN_AdvanceMover(char *, unsigned short *);
void BOX2_MAIN_StepMover(char *p, int a, int b)
{
    unsigned short *q = *(unsigned short **)(*(int *)&((struct Obj00000 *)p)->f2C + 0x60);
    q[0] = 0x24;
    q[1] = b;
    q[2] = a;
    q[3] = 1;
    BOX2_MAIN_AdvanceMover(p, q);
    q[12] = (unsigned short)b;
    q[13] = a;
    q[14] = (unsigned short)b;
    q[15] = 1;
    BOX2_MAIN_AdvanceMover(p, q + 12);
}
