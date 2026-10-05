/*
 * function: func_0219E664
 * address:  0x0219E664
 * packet:   pkt_ov021_0219E664
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D530  0x0216D530  thumb  ov010
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_021BB480  0x021BB480  thumb  ov021
 *   func_0219E2F4  0x0219E2F4  thumb  ov021
 *   func_0201441C  0x0201441C  thumb
 *   func_021B7CD8  0x021B7CD8  thumb  ov021
 *   func_021B7E60  0x021B7E60  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0216D67C(void *);
extern void *func_0216D530(void *);
extern void *func_0216D69C(void *);
extern u16 func_0216D5F8(void *p);
extern void *func_021BB480(void *);
extern void func_0219E2F4(void *o, void *out);
extern u8 func_0201441C(int i);
extern int func_021B7CD8(void *m, void *r, u32 key, void *out);
extern int func_021B7E60(void *c, u32 key, void *out, void *pos);

int func_0219E664(void *o, u32 k, void *buf)
{
    void *h;
    u32 t;
    void **p;

    h = func_021BB480(func_0216D530(func_0216D67C(o)));
    t = func_0216D5F8(o);
    p = func_0216D69C(o);
    if (t != k) {
        func_0219E2F4(o, buf);
        return func_021B7CD8(h, buf, func_0201441C(k), buf);
    }
    return func_021B7E60(*p, func_0201441C(k), buf, 0);
}
