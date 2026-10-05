/*
 * function: func_021585BC
 * address:  0x021585BC
 * packet:   pkt_021585BC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02175B14  0x02175B14  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02175B14();

int func_021585BC(int a0, int a1)
{

a1 = 0x25;
a1 = a1 << 6;
a1 = *(int *)((char *)a0 + a1);
a1 = (unsigned)a1 >> 0x1f;
    if (a1 == 0) goto loc_021585DA;
loc_021585C8:
a1 = 0x6b;
a1 = a1 << 2;
a0 = a0 + a1;
    a0 = func_02175B14(a0, a1);
loc_021585D2:
    if (a0 != 0) goto loc_021585DA;
loc_021585D6:
a0 = 1;
    return a0;
loc_021585DA:
a0 = 0;
    return a0;}
