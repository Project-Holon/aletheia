/*
 * function: func_021598AC
 * address:  0x021598AC
 * packet:   pkt_021598AC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 *func_02159AE8(void *a0, void *a1);

int func_021598AC(int a0, int a1)
{
    int t5;
    int t6;
    u16 *q;
    u16 *dst;

t5 = a0 + 0;
t6 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_021598B6:
a0 = t5 + 0;
a1 = t6 + 0;
    dst = func_02159AE8((void *)a0, (void *)a1);
loc_021598C0:
a0 = *dst;
*q = a0;
a0 = 0;
    return a0;}
