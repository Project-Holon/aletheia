/*
 * function: func_021B574C
 * address:  0x021B574C
 * packet:   pkt_ov021_021B574C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * func_0201A354 is filed as src/matched/arm9/func_0201A354.c (witness).
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_0201A354  0x0201A354  thumb
 *   func_021B58B0  0x021B58B0  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_0215897C  0x0215897C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5F4();
extern int func_0215A5DC();
extern int func_02159B10();
extern int func_02159AE8();
extern int func_0215A5CC();
extern int func_0201A354();
extern int func_021B58B0();
extern void func_020307B0();
extern void func_0215897C();

int func_021B574C(int a0, int a1)
{
    int s8 = func_0215A5F4(a1);
    int s4 = func_0215A5DC(a1);
    int r4 = func_02159B10(a0, a1);
    int r7 = func_02159AE8(a0, a1);
    int r6 = func_0215A5CC(a1);
    int r5 = func_0201A354(r4, r6);
    int r1 = 1;
    u16 d = r4 + 0xffec;

    if (d > 2) {
        r1 = 0;
    }
    r4 = func_021B58B0(s4, r1, r5, r7, r6);
    func_020307B0(r5);
    if (r4 == 0) {
        return 0;
    }
    func_0215897C(s8, r4);
    return 1;
}
