/*
 * function: func_021595A0
 * address:  0x021595A0
 * packet:   pkt_021595A0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215AA4C  0x0215AA4C  thumb  ov010
 *   func_021587E0  0x021587E0  thumb  ov010
 *   func_0215AA34  0x0215AA34  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5F4();
extern int func_0215AA4C();
extern int func_021587E0();
extern int func_0215AA34();

int func_021595A0(int a0, int a1)
{
    int t4;
    int t5;

t5 = a1 + 0;
a0 = t5 + 0;
    a0 = func_0215A5F4(a0);
loc_021595AA:
t4 = a0 + 0;
a0 = t5 + 0;
    a0 = func_0215AA4C(a0);
loc_021595B2:
a1 = a0 + 0;
a0 = t4 + 0;
    a0 = func_021587E0(a0, a1);
loc_021595BA:
    if (a0 != 0) goto loc_021595C8;
loc_021595BE:
a0 = t5 + 0;
    a0 = func_0215AA34(a0);
loc_021595C4:
a0 = 1;
    return a0;
loc_021595C8:
a0 = 0;
    return a0;}
