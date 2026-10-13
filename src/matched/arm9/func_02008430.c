/*
 * function: CONFIG_SetButtonMode
 * address:  0x02008430
 * packet:   pkt_02008430
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf setter on a u16 bitfield word (witness for ov068 callers).
 *
 * symbols:
 *   CONFIG_SetButtonMode  0x02008430  thumb
 */

typedef struct {
    unsigned short a : 4;
    unsigned short b : 2;
    unsigned short c : 1;
    unsigned short d : 1;
    unsigned short e : 1;
    unsigned short f : 1;
} BF;

void CONFIG_SetButtonMode(BF *p, unsigned int v) { p->f = (unsigned short)v; }
