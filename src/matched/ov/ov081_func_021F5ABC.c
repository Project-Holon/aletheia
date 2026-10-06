/*
 * function: func_021F5ABC
 * address:  0x021F5ABC
 * packet:   pkt_ov081_021F5ABC
 * region:   ov081
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F5620  0x021F5620  thumb  ov077
 *   func_021F5AEC  0x021F5AEC  thumb  ov081
 *   func_021F5B30  0x021F5B30  thumb  ov081
 *   func_021F5B94  0x021F5B94  thumb  ov081
 * Addresses are Black-image addresses.
 */

typedef struct {
    int w;
    int h;
    void (*init)(void *);
    void (*step)(void *);
    int (*done)(void *);
} Cfg;

typedef unsigned char  u8;
struct Param;
extern void *func_021F5620(void *task, const struct Param *p, int flag);
extern void func_021F5AEC(u8 *w);
extern void func_021F5B30(u8 *w);
extern int func_021F5B94(int *o);

void func_021F5ABC(void *a)
{
    Cfg c;

    c.w = 2;
    c.h = 2;
    c.init = (void (*)(void *))func_021F5AEC;
    c.step = (void (*)(void *))func_021F5B30;
    c.done = (int (*)(void *))func_021F5B94;
    func_021F5620(a, (const struct Param *)(&c), 1);
}
