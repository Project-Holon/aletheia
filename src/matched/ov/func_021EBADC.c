/*
 * function: BOX2_SEQ_PrintMessageB
 * address:  0x021EBADC
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_PrintMessageMsg  0x021EBA84  thumb  ov170
 *
 * Sibling of BOX2_SEQ_PrintMessageC: index 0x34 when state is 5, else 0xb.
 */
#include "../include/Obj18517.h"


extern void BOX2_SEQ_PrintMessageMsg(unsigned char *p, int msg, int i);
void BOX2_SEQ_PrintMessageB(char *p, int b)
{
    if (*(int *)(((struct Obj18517 *)p)->f0 + 0x24) == 5)
        BOX2_SEQ_PrintMessageMsg((unsigned char *)p, 0x34, b);
    else
        BOX2_SEQ_PrintMessageMsg((unsigned char *)p, 0xb, b);
}
