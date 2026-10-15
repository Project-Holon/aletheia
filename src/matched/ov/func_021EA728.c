/*
 * function: BOX2_SEQ_CreateB
 * address:  0x021EA728
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * Sibling of BOX2_SEQ_Create with (0x1c, 0) and the 0x228F buffer.
 */
#include "../include/Obj18488.h"

extern void *func_02030734(unsigned int heap, unsigned int size, int clear, const char *site, unsigned short tag);


void BOX2_SEQ_CreateB(void *p)
{
    int v = (int)func_02030734(0x4c, 0x1c, 0, (const char *)0x021F140C, 0x228F);
    *(int *)(((struct Obj18488 *)p)->f2C + 0x60) = v;
}
