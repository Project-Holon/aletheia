/*
 * function: func_021F5ABC
 * address:  0x021F5ABC
 * packet:   pkt_ov079_021F5ABC
 * region:   ov079
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F5620  0x021F5620  thumb  ov077
 *   func_021F5AE4  0x021F5AE4  thumb  ov079
 *   func_021F5B24  0x021F5B24  thumb  ov079
 * Addresses are Black-image addresses.
 */

typedef struct {
    int w;
    int h;
    int z;
    void (*step)(void *);
    int (*done)(void *);
} Cfg;

extern void func_021F5620(void *a, Cfg *c, int b);
extern void func_021F5AE4(void *w);
extern int func_021F5B24(void *o);

void func_021F5ABC(void *a)
{
    Cfg c;

    c.w = 4;
    c.h = 4;
    c.z = 0;
    c.step = func_021F5AE4;
    c.done = func_021F5B24;
    func_021F5620(a, &c, 0);
}
