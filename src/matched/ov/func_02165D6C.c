/*
 * function: func_02165D6C
 * address:  0x02165D6C
 * packet:   pkt_02165D6C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204581C  0x0204581C  arm
 *   func_02045924  0x02045924  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0204581C();
extern int func_02045924();

int func_02165D6C(int a0, int a1, int a2)
{

a2 = a0 + 0;
a0 = *(u16 *)((char *)a2 + 0x30);
    if (a0 == 0x18) goto loc_02165D7E;
loc_02165D76:
a0 = a1 + 0;
    a0 = func_0204581C(a0);
loc_02165D7C:
    return a0;
loc_02165D7E:
a2 = a2 + 0x34;
a0 = a1 + 0;
a1 = a2 + 0;
    a0 = func_02045924(a0, a1);
loc_02165D88:
    return a0;}
