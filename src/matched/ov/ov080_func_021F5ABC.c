/*
 * function: func_021F5ABC
 * address:  0x021F5ABC
 * packet:   pkt_ov080_021F5ABC
 * region:   ov080
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F5620  0x021F5620  thumb  ov077
 *   func_021F5AE8  0x021F5AE8  thumb  ov080
 *   func_021F5B44  0x021F5B44  thumb  ov080
 * Addresses are Black-image addresses.
 */

typedef struct {
    int w;
    int h;
    void (*init)(void *);
    void (*step)(void *);
    int (*done)(void *);
} Cfg;

extern void func_021F5620(void *a, Cfg *c, int b);
extern void func_021F5AE8(void *w);
extern int func_021F5B44(void *o);

void func_021F5ABC(void *a)
{
    Cfg c;

    c.w = 2;
    c.h = 2;
    c.init = 0;
    c.step = func_021F5AE8;
    c.done = func_021F5B44;
    func_021F5620(a, &c, 1);
}
