/*
 * function: func_0215F104
 * address:  0x0215F104
 * packet:   pkt_0215F104
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



int func_0215F104(int a0, int a1, int a2, int a3)
{

a3 = *(u16 *)((char *)a0 + 2);
a2 = 1;
a2 = a2 << a1;
a1 = a3 + 0;
a0 = 1;
    if ((a1 & a2) != 0) goto loc_0215F114;
loc_0215F112:
a0 = 0;
loc_0215F114:
    return a0;}
