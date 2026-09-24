/*
 * function: func_0216D600
 * address:  0x0216D600
 * packet:   pkt_0216D600
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



int func_0216D600(int a0, int a1, int a2)
{

a2 = *(u16 *)((char *)a0 + 0x1a);
*(u16 *)((char *)a0 + 0x1e) = a2;
*(u16 *)((char *)a0 + 0x1a) = a1;
    return a0;}
