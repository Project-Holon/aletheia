/*
 * function: func_02161D64
 * address:  0x02161D64
 * packet:   pkt_02161D64
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02013A80  0x02013A80  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02013A80();

int func_02161D64(int a0, int a1)
{
    int t4;

t4 = a0 + 0;
a0 = *(u16 *)((char *)t4 + 2);
    if (a0 != 1) goto loc_02161D7E;
loc_02161D6E:
a0 = 0;
a1 = 1;
    a0 = func_02013A80(a0, a1);
loc_02161D76:
a0 = 1;
a1 = 1;
    a0 = func_02013A80(a0, a1);
loc_02161D7E:
a0 = *(u16 *)((char *)t4 + 2);
    if (a0 != 0) goto loc_02161D94;
loc_02161D84:
a0 = 0;
a1 = 0;
    a0 = func_02013A80(a0, a1);
loc_02161D8C:
a0 = 1;
a1 = 0;
    a0 = func_02013A80(a0, a1);
loc_02161D94:
    return a0;}
