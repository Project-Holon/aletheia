/*
 * function: func_0215AADC
 * address:  0x0215AADC
 * packet:   pkt_0215AADC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A610  0x0215A610  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 *func_02159AE8(void *a0, void *a1);
extern u16 func_0215A610(void *p);

int func_0215AADC(int a0, int a1)
{
    int t5;
    u16 *q;

t5 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215AAE4:
a0 = t5 + 0;
    a0 = func_0215A610((void *)a0);
loc_0215AAEC:
*q = a0;
a0 = 0;
    return a0;}
