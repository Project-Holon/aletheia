/*
 * function: func_0216A470
 * address:  0x0216A470
 * packet:   pkt_ov010_0216A470
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012F50  0x02012F50  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02168BF0  0x02168BF0  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5F4();
extern int func_0215A5DC();
extern int func_020120F4(int a);
extern int func_02012F50(int base);
extern int func_02159B10();
extern int func_02159AE8();
extern int func_02168BF0();
extern int func_0215897C();

int func_0216A470(int a0, int a1)
{
    int r7;
    int l4;
    int *r6;
    int l8;
    int lc;
    int l0;

    r7 = func_0215A5F4(a1);
    l4 = func_0215A5DC(a1);
    r6 = (int *)func_02012F50(func_020120F4(l4));
    l8 = func_02159B10(a0, a1);
    lc = func_02159B10(a0, a1);
    l0 = func_02159AE8(a0, a1);
    func_0215897C(r7, func_02168BF0(l4, *r6, l8, lc, l0));
    return 1;
}
