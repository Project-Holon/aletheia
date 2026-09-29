/*
 * function: func_0216A4CC
 * address:  0x0216A4CC
 * packet:   pkt_ov010_0216A4CC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012F50  0x02012F50  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_021D0AC0  0x021D0AC0  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5F4();
extern int func_0215A5DC();
extern int func_020120F4();
extern int *func_02012F50();
extern int func_02159B10();
extern u16 *func_02159AE8();
extern u16 func_021D0AC0();

int func_0216A4CC(int a0, int a1)
{
    int r7;
    int *r6;
    int loc;
    u16 *p;

    func_0215A5F4(a1);
    r7 = func_0215A5DC(a1);
    func_020120F4();
    r6 = func_02012F50();
    loc = func_02159B10(a0, a1);
    p = func_02159AE8(a0, a1);
    *p = func_021D0AC0(r7, *r6, loc);
    return 0;
}
