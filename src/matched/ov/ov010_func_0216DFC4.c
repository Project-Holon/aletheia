/*
 * function: func_0216DFC4
 * address:  0x0216DFC4
 * packet:   pkt_ov010_0216DFC4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_0216D598  0x0216D598  thumb  ov010
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0216D67C(void *a);
extern int func_0216DD1C(void *c, void **out, u32 *iter);
extern u16 func_0216D598(void *p);

int func_0216DFC4(void *a, u32 id)
{
    u32 iter = 0;
    void *out;
    void *ctx;

    ctx = func_0216D67C(a);
    while (func_0216DD1C(ctx, &out, &iter) == 1) {
        if (out != a) {
            u32 v = func_0216D598(out);
            if (v != 0xFFFF && v == id)
                return 1;
        }
    }
    return 0;
}
