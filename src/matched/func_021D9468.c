/*
 * function: func_021D9468
 * address:  0x021D9468
 * packet:   pkt_021D8980
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Start a transfer on the object when the length is non-zero.
 *
 * symbols:
 *   func_021E36D8  0x021E36D8  thumb  ov119
 *   func_021D8AA8  0x021D8AA8  thumb  ov119
 *   func_021E36A8  0x021E36A8  thumb  ov119
 *   func_021E1B14  0x021E1B14  thumb  ov119
 */

extern void func_021E36D8(void *p);
extern int func_021D8AA8(void *p);
extern void func_021E36A8(void *p, int a, int b, int c, int d, int e);
extern void func_021E1B14(void *p, int a, int b);

void func_021D9468(void *p, int a, int b)
{
    int t;

    if (b == 0)
        return;
    func_021E36D8(p);
    t = func_021D8AA8(p);
    func_021E36A8(p, a, 1 - a, b, 1, t);
    func_021E1B14(p, a, b);
}

