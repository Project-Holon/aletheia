/*
 * function: func_021B1550
 * address:  0x021B1550
 * packet:   pkt_ov021_021B1550
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020362DC  0x020362DC  arm
 *   func_0215A61C  0x0215A61C  thumb  ov010
 *   func_020061E4  0x020061E4  thumb
 *   func_02159190  0x02159190  thumb  ov010
 *   func_02191134  0x02191134  thumb  ov021
 *   func_02191794  0x02191794  thumb  ov021
 *   func_021914CC  0x021914CC  thumb  ov021
 */

typedef unsigned int u32;

u32 func_020362DC(void);
int func_0215A61C(int a);
void func_020061E4(u32 a);
int func_02159190(int a);
struct P;
struct R;
struct S;
void func_02191134(struct P *p);
void func_02191794(struct R *r);
void func_021914CC(struct S *s);

int func_021B1550(int a, int b)
{
    int r5;
    int r4;

    r5 = func_020362DC();
    r4 = func_0215A61C(b);
    if (r5 & 3) {
        func_020061E4(0x547);
        return 1;
    }
    if (func_02159190(1)) {
        func_02191134((struct P *)r4);
    } else if (func_02159190(3)) {
        func_02191794((struct R *)r4);
    } else if (func_02159190(2)) {
        func_021914CC((struct S *)r4);
    } else {
        return 1;
    }
    return 0;
}
