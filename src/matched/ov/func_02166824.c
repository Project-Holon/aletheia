/*
 * function: func_02166824
 * address:  0x02166824
 * packet:   pkt_02166824
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



int func_02166824(int a0, int a1)
{
    int a2;
a2 = *(u8 *)((char *)a0 + 1);
    if ((unsigned)a1 < (unsigned)a2) goto loc_0216682E;
loc_0216682A:
a0 = 0xb;
    return a0;
loc_0216682E:
a0 = a0 + a1;
a0 = *(u8 *)((char *)a0 + 3);
    return a0;}
