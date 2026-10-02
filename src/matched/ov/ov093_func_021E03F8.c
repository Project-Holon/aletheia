/*
 * function: func_021E03F8
 * address:  0x021E03F8
 * packet:   pkt_ov093_021E03F8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D732C  0x021D732C  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021D7040  0x021D7040  thumb  ov093
 *   func_021D7360  0x021D7360  thumb  ov093
 */

extern void *func_021D732C(int a, int b);
extern int func_021D70A8(void *a);
extern void func_021D7040(void *n);
extern void *func_021D7360(void *n);

void func_021E03F8(int a, int b)
{
    void *n = func_021D732C(0, a);

    while (n != 0) {
        if (b == func_021D70A8(n)) {
            func_021D7040(n);
            n = func_021D732C(0, a);
        } else {
            n = func_021D7360(n);
        }
    }
}
