/*
 * function: func_021588B0
 * address:  0x021588B0
 * packet:   pkt_021588B0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none: no relocation site)
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;



int func_021588B0(int a0, int a1, int a2)
{

a2 = a0 + 0;
a0 = a1 + 0;
a1 = *(int *)((char *)a2 + 0x14);
a2 = *(int *)((char *)a2 + 0x10);
    a0 = ((int (*)())a2)(a0, a1, a2);
loc_021588BC:
    return a0;}
