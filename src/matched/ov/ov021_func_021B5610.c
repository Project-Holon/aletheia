/*
 * function: func_021B5610
 * address:  0x021B5610
 * packet:   pkt_ov021_021B5610
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_021F36C0  0x021F36C0  thumb  ov037
 *   func_0215897C  0x0215897C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(void *p);
extern int func_02159B10();
extern int func_021F36C0();
extern int func_0215897C();

int func_021B5610(int a0, int a1)
{
    void *r6 = func_0215A5F4((void *)a1);
    void *r7 = func_0215A5DC((void *)a1);
    void *t = func_0201210C();
    int v = func_02159B10(a0, a1);

    func_0215897C(r6, func_021F36C0(r7, t, (u16)(v - 1)));
    return 1;
}
