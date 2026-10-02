/*
 * function: func_021595CC
 * address:  0x021595CC
 * packet:   pkt_ov010_021595CC
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
 *   func_02011330  0x02011330  thumb
 *   func_0215A5D4  0x0215A5D4  thumb  ov010
 *   func_0215A5D8  0x0215A5D8  thumb  ov010
 *   func_02159B38  0x02159B38  thumb  ov010
 *   func_021589A0  0x021589A0  thumb  ov010
 *   func_0215AA48  0x0215AA48  thumb  ov010
 *   func_0215AA24  0x0215AA24  thumb  ov010
 *   func_0215AA34  0x0215AA34  thumb  ov010
 *   func_02158A34  0x02158A34  thumb  ov010
 *   func_020113D0  0x020113D0  thumb
 *   func_021595A0  0x021595A0  thumb  ov010
 */

extern void *func_0215A5DC(void *a0);
extern void *func_0215A5F4(void *p);
extern int func_02011330(int);
extern int func_0215A5D4(int);
extern int func_0215A5D8(int);
extern int func_02159B38(int);
extern int func_021589A0(int, int, int);
extern void func_0215AA48(int, int);
extern void func_0215AA24(int);
extern void func_0215AA34(int);
extern void func_02158A34(int, int, int, int);
extern void func_020113D0(int, int (*)(int));
extern int func_021595A0(int);

int func_021595CC(int a, int b)
{
    void *x = func_0215A5DC((void *)b);
    void *y = func_0215A5F4((void *)b);
    int z = func_02011330(a);
    if (func_0215A5D4(b) == 0) {
        func_0215AA48(b, func_021589A0(y, func_02159B38(b), z));
        func_0215AA24(b);
        func_020113D0(a, func_021595A0);
        return 1;
    }
    func_0215AA24(b);
    func_02158A34(x, y, z, func_0215A5D8(b));
    func_0215AA34(b);
    return 0;
}
