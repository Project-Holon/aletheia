/*
 * function: func_0218562C
 * address:  0x0218562C
 * packet:   pkt_ov020_0218562C
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012914  0x02012914  thumb
 *   func_02159FA8  0x02159FA8  thumb  ov010
 *   func_02159F94  0x02159F94  thumb  ov010
 *   func_02014204  0x02014204  thumb
 *   func_020128C0  0x020128C0  thumb
 *   func_02185B70  0x02185B70  thumb  ov020
 *   func_02185A68  0x02185A68  thumb  ov020
 *   func_021857C0  0x021857C0  thumb  ov020
 *   func_0202735C  0x0202735C  thumb
 *   func_02168EEC  0x02168EEC  thumb  ov010
 *   func_0216446C  0x0216446C  thumb  ov010
 */

typedef unsigned short u16;

int func_020120F4(int a);
int func_02012914(int a);
void func_02159FA8(int a, void *b);
typedef unsigned int   u32;
u16 func_02159F94(int a);
void func_02014204(void *buf, int n);
void func_020128C0(int a, void *b);
void func_02185B70(int a);
void func_02185A68(int a, int b);
void func_021857C0(int a, void *b);
void func_0202735C(u32 a0, u32 a1);
void func_02168EEC(int a);
int func_0216446C(int a, int b);

void func_0218562C(int a)
{
    int r4 = func_020120F4(a);
    struct { char b[0x1c]; int f; u16 h; char pad[0x16]; } l;

    func_02159FA8(func_02012914(r4), &l.f);
    func_02014204(l.b, func_02159F94(func_02012914(r4)));
    func_020128C0(r4, l.b);
    func_02185B70(a);
    func_02185A68(a, l.h);
    func_021857C0(a, &l.f);
    func_0202735C(l.h, r4);
    func_02168EEC(r4);
    func_0216446C(r4, l.h);
}
