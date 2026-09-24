/*
 * function: func_0215BFD4
 * address:  0x0215BFD4
 * packet:   pkt_0215BFD4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_0215B4AC  0x0215B4AC  thumb  ov010
 *   func_0216F948  0x0216F948  thumb  ov010
 *   func_0216FAA0  0x0216FAA0  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02159AE8();
extern int func_02159B10();
extern int func_0215A5CC();
extern int func_0215B4AC();
extern int func_0216F948();
extern int func_0216FAA0();
extern int func_020307B0();

int func_0215BFD4(int a0, int a1, int a2)
{
    int v0;
    int t4;
    int t5;
    int t6;
    int t7;
t6 = a0 + 0;
t5 = a1 + 0;
    a0 = func_02159AE8(a0, a1);
loc_0215BFDE:
t4 = a0 + 0;
a0 = t6 + 0;
a1 = t5 + 0;
    a0 = func_02159B10(a0, a1);
loc_0215BFE8:
t6 = a0 + 0;
a0 = t5 + 0;
    a0 = func_0215A5CC(a0);
loc_0215BFF0:
t7 = a0 + 0;
a0 = t5 + 0;
a1 = t6 + 0;
a2 = (int)&v0;
    a0 = func_0215B4AC(a0, a1, a2);
loc_0215BFFC:
    if (a0 != 1) goto loc_0215C016;
loc_0215C000:
    a0 = v0;
a1 = t7 + 0;
    a0 = func_0216F948(a0, a1);
loc_0215C008:
t5 = a0 + 0;
    a0 = func_0216FAA0(a0);
loc_0215C00E:
*(u16 *)((char *)t4) = a0;
a0 = t5 + 0;
    a0 = func_020307B0(a0);
loc_0215C016:
a0 = 0;
    return a0;
}
