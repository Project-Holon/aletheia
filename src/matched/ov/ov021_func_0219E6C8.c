/*
 * function: func_0219E6C8
 * address:  0x0219E6C8
 * packet:   pkt_ov021_0219E6C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D530  0x0216D530  thumb  ov010
 *   func_021BB480  0x021BB480  thumb  ov021
 *   func_0219E2F4  0x0219E2F4  thumb  ov021
 *   func_0201441C  0x0201441C  thumb
 *   func_021B7C90  0x021B7C90  thumb  ov021
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D80C  0x0216D80C  thumb  ov010
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_0216D818  0x0216D818  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D824  0x0216D824  thumb  ov010
 *   func_0216D844  0x0216D844  thumb  ov010
 *   func_0216D85C  0x0216D85C  thumb  ov010
 *   func_0216D874  0x0216D874  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

struct Mgr;
extern void *func_0216D67C(void *a0);
extern void *func_0216D530(void *p);
extern void *func_021BB480(void *p);
extern void func_0219E2F4(void *o, void *out);
extern u8 func_0201441C(int i);
extern int func_021B7C90(struct Mgr *m, void *r, void *key, void *q);
extern int func_0216D83C(void *p);
extern void func_0216D80C();
extern int func_0216D854(void *p);
extern void func_0216D818();
extern int func_0216D86C(void *p);
extern void func_0216D824();
extern void func_0216D844(void *p, short v);
extern void func_0216D85C(void *p, int v);
extern void func_0216D874(int a0, int a1);

void func_0219E6C8(u32 o, u16 id)
{
    u32 h;
    s32 v[3];
    u32 a[2];

    h = (u32)func_021BB480(func_0216D530(func_0216D67C((void *)o)));
    func_0219E2F4((void *)o, a);
    func_021B7C90((struct Mgr *)h, a, (void *)func_0201441C(id), v);
    func_0216D80C(o, func_0216D83C((void *)o));
    func_0216D818(o, func_0216D854((void *)o));
    func_0216D824(o, func_0216D86C((void *)o));
    func_0216D844((void *)o, (v[0] >> 4) / 4096);
    func_0216D85C((void *)o, (s16)((v[1] >> 4) / 4096));
    func_0216D874((u32)o, (s16)((v[2] >> 4) / 4096));
}
