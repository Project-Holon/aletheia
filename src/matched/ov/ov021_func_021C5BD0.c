/*
 * function: func_021C5BD0
 * address:  0x021C5BD0
 * packet:   pkt_ov021_021C5BD0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Spawns the func_021C5C08 task with a 0x14-byte work area.
 *
 * symbols:
 *   func_021C5C08  0x021C5C08  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *owner;
    u32 f4;
    u32 f8;
    u16 hC;
    u16 pad;
    u32 f10;
} W;

void *func_020122C0(void *p, int a, void (*cb)(void), int n);
void *func_020124E8(void *p);
extern void *func_0201210C(void *p);
extern u32 func_020120F4(void *p);
void func_021C5C08(void);

void *func_021C5BD0(void *a, u16 b, u32 c)
{
    void *t = func_020122C0(a, 0, func_021C5C08, 0x14);
    W *w = func_020124E8(t);

    w->owner = a;
    w->f4 = func_0201210C((u32)a);
    w->f10 = c;
    w->f8 = func_020120F4(a);
    w->hC = b;
    return t;
}
