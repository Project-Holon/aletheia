/*
 * function: func_0215AA50
 * address:  0x0215AA50
 * packet:   pkt_0215AA50
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 *func_02159AE8(void *a0, void *a1);

int func_0215AA50(int a0, int a1)
{
    u16 *q;

    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215AA56:
a1 = 0x15;
*q = a1;
a0 = 0;
    return a0;}
