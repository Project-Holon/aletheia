/*
 * function: func_0216A7A0
 * address:  0x0216A7A0
 * packet:   pkt_ov010_0216A7A0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_0216A838  0x0216A838  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int a;
    int b;
    int c;
} Vec3;

typedef struct {
    int f0;
    u16 f4;
    u16 f6;
    int f8;
    Vec3 v;
} S;

extern int func_0215A5E4();
extern int func_0215A5F4();
extern int func_0215A5DC();
extern int func_02159B10();
extern int func_020122C0();
extern S *func_020124E8(int p);
extern int func_0201210C(int a);
extern int func_02188C7C(int p);
extern int func_0216DE94();
extern void func_0216D88C();
extern void func_0216D568();
extern void func_0215897C();
extern int func_0216A838();

int func_0216A7A0(int a0, int a1)
{
    int l0;
    int r6;
    int l4;
    int r7;
    int r5;
    int l8;
    S *r4;

    func_0215A5E4(a1);
    l0 = func_0215A5F4(a1);
    r6 = func_0215A5DC(a1);
    l4 = func_02159B10(a0, a1);
    r7 = func_02159B10(a0, a1);
    r5 = func_02159B10(a0, a1);
    l8 = func_020122C0(r6, 0, func_0216A838, 0x18);
    r4 = func_020124E8(l8);
    r4->f4 = r5;
    r4->f6 = 0;
    r5 = func_0216DE94(func_02188C7C(func_0201210C(r6)), l4);
    func_0216D88C(r5, &r4->v);
    r4->f8 = r5;
    func_0216D568(r5, 0x8000);
    r4->f0 = (r7 << 15) - r4->v.b;
    func_0215897C(l0, l8);
    return 1;
}
