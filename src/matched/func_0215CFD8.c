/*
 * function: func_0215CFD8
 * address:  0x0215CFD8
 * packet:   pkt_0215CFD8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D50  0x02188D50  thumb
 *   func_021C34C4  0x021C34C4  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02159AE8();
extern int func_0215A5DC();
extern int func_0201210C();
extern int func_02188D50();
extern int func_021C34C4();

int func_0215CFD8(int a0, int a1)
{
    int t4;
    int t5;

t5 = a1 + 0;
    a0 = func_02159AE8();
loc_0215CFE0:
t4 = a0 + 0;
a0 = t5 + 0;
    a0 = func_0215A5DC(a0);
loc_0215CFE8:
    a0 = func_0201210C();
loc_0215CFEC:
    a0 = func_02188D50();
loc_0215CFF0:
    a0 = func_021C34C4();
loc_0215CFF4:
*(u16 *)((char *)t4) = a0;
a0 = 0;
    return a0;}
