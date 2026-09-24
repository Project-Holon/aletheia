/*
 * function: func_0215B3AC
 * address:  0x0215B3AC
 * packet:   pkt_0215B3AC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215F6E8  0x0215F6E8  thumb  ov010
 *   func_0215898C  0x0215898C  thumb  ov010
 *   func_02011290  0x02011290  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5DC();
extern int func_0215A5F4();
extern int func_0215F6E8();
extern int func_0215898C();
extern int func_02011290();

int func_0215B3AC(int a0, int a1)
{
    int t4;
    int t5;
    int t6;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    a0 = func_0215A5DC(a0);
loc_0215B3B8:
t4 = a0 + 0;
a0 = t6 + 0;
    a0 = func_0215A5F4(a0);
loc_0215B3C0:
t6 = a0 + 0;
a0 = t4 + 0;
    a0 = func_0215F6E8(a0);
loc_0215B3C8:
a1 = a0 + 0;
a0 = t6 + 0;
    a0 = func_0215898C(a0, a1);
loc_0215B3D0:
a0 = t5 + 0;
    a0 = func_02011290(a0);
loc_0215B3D6:
a0 = 1;
    return a0;}
