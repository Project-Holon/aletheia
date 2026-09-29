/*
 * function: func_021F36C0
 * address:  0x021F36C0
 * packet:   pkt_ov059_021F36C0
 * region:   ov059
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   d_021F3E94  0x021F3E94  data  a4
 */

typedef unsigned short u16;

extern int func_02188D2C(int a);
extern int func_02188C84(int a);
extern void func_02189764(int a, int b, int c, int d);
extern void func_021BE760(int a, void *b, int c);
extern void func_021BE4B4(int a, int b, int c, int d);
extern int func_021BE674(int a, int b, int c, u16 d);
extern void func_021BE6B8(int a, int b);
extern void func_021BE6B0(int a, int b);
extern void func_021BE700(int a, int b, int c, u16 d, int e);
extern char d_021F3E94[];

void func_021F36C0(int a)
{
    int i;
    int r5;
    int z;
    int r7;

    r5 = func_02188D2C(a);
    func_02189764(a, 1, func_02188C84(a), 0x28);
    func_021BE760(r5, d_021F3E94, 0);
    i = 0;
    func_021BE4B4(r5, 0, 1, 1);
    func_021BE4B4(r5, 0, 0, 1);
    for (i = 0; i < 3; i++) {
        z = 0;
        r7 = func_021BE674(r5, z, z, i);
        func_021BE6B8(r7, z);
        func_021BE6B0(r7, 1);
        func_021BE700(r5, z, z, i, z);
        r7 = func_021BE674(r5, z, 1, i);
        func_021BE6B8(r7, z);
        func_021BE6B0(r7, 1);
        func_021BE700(r5, z, 1, i, z);
    }
}
