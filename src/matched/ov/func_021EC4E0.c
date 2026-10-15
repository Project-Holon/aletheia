/*
 * function: BOX2_SEQ_ShowAllSlotIcons
 * address:  0x021EC4E0
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_ShowSlotIcon  0x021EC48C  thumb  ov170
 *
 * Loop 0x1e entries forwarding (p[0x14], i, i+0x33).
 */
#include "../include/Obj18520.h"


extern void BOX2_SEQ_ShowSlotIcon(unsigned char *p, int box, int pos, int win);
void BOX2_SEQ_ShowAllSlotIcons(char *p)
{
    unsigned i;
    for (i = 0; i < 0x1e; i++)
        BOX2_SEQ_ShowSlotIcon((unsigned char *)p, ((struct Obj18520 *)p)->f14, i, i + 0x33);
}
