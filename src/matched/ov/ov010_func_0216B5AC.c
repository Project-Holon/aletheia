/*
 * function: func_0216B5AC
 * address:  0x0216B5AC
 * packet:   pkt_ov010_0216B5AC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0200C33C  0x0200C33C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5F4();
extern int func_0215A5E4();
extern int func_02012EBC(int p);
extern int func_0200C0F0(int sys);
extern u16 *func_02159AE8();
extern u16 func_0200C33C();

int func_0216B5AC(int a0, int a1)
{
    int h;
    u16 *p0;
    u16 *p1;
    u16 *p2;

    func_0215A5F4(a1);
    h = func_0200C0F0(func_02012EBC(func_0215A5E4(a1)));
    p0 = func_02159AE8(a0, a1);
    p1 = func_02159AE8(a0, a1);
    p2 = func_02159AE8(a0, a1);
    *p0 = func_0200C33C(h, 0);
    *p1 = func_0200C33C(h, 1);
    *p2 = func_0200C33C(h, 2);
    return 0;
}
