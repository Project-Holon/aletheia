/*
 * function: func_0215EA38
 * address:  0x0215EA38
 * packet:   pkt_0215EA38
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215F0B8  0x0215F0B8  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215F0B8(u16 *p, int i);

int func_0215EA38(int a0, int a1, int a2, int a3)
{
    int t4;
    int t5;

a3 = a0 + 0;
t4 = a2 + 0;
t5 = a1 + 0;
a0 = t4 + 0;
a1 = a3 + 0;
    a0 = func_0215F0B8((u16 *)a0, a1);
loc_0215EA48:
a2 = a0 + 0;
    if (a2 != 0) goto loc_0215EA50;
loc_0215EA4C:
a0 = 0;
    return a0;
loc_0215EA50:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = ((int (*)())a2)(a0, a1);
loc_0215EA56:
    return a0;}
