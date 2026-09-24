/*
 * function: func_0216D508
 * address:  0x0216D508
 * packet:   pkt_0216D508
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



int func_0216D508(int a0, int a1)
{

a1 = 6;
a1 = *(short *)((char *)a0 + a1);
a1 = a1 - 1;
*(u16 *)((char *)a0 + 6) = a1;
    return a0;}
