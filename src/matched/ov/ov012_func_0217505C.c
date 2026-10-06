/*
 * function: func_0217505C
 * address:  0x0217505C
 * packet:   pkt_ov012_0217505C
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_0216754C  0x0216754C  thumb  ov010
 */

typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
struct O;
extern void func_0216754C(int a, struct O *o);

void func_0217505C(int *p, int x)
{
    int i;

    for (i = 0; i < 4; i++) {
        func_020307B0(*(void **)((char *)p + i * 4 + 0x134));
        func_020307B0(*(void **)((char *)p + i * 4 + 0x148));
    }
    func_0216754C(x, (struct O *)(*p));
    func_020307B0(p);
}
