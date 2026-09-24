/*
 * function: func_02156FC4
 * address:  0x02156FC4
 * packet:   pkt_02156FC4
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



int func_02156FC4(int a0, int a1, int a2, int a3)
{

a3 = a0 + 4;
a0 = a1 << 2;
*(int *)((char *)a3 + a0) = a2;
a0 = 0;
*(int *)((char *)a2) = a0;
    return a0;}
