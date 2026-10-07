/*
 * function: func_021C3204
 * address:  0x021C3204
 * packet:   pkt_ov021_021C3204
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0200BCB8  0x0200BCB8  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_021C3248  0x021C3248  thumb  ov021
 *   func_021C3250  0x021C3250  thumb  ov021
 *   func_0200BC4C  0x0200BC4C  thumb
 *   func_0201A9C8  0x0201A9C8  thumb
 *   func_021C38DC  0x021C38DC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern int func_0200BCB8(u32);
extern void *func_0201AB28(void *p, u32 idx);
extern void func_021C3248(void);
typedef signed int     s32;
struct Obj;
struct Party;
struct Payload;
extern void func_021C3250(void *mon);
extern void func_0200BC4C(struct Obj *p, s32 i, const struct Payload *src);
extern u32 func_0201A9C8(struct Party *p, s32 idx);
extern int func_021C38DC(u32 a, u32 b);

void func_021C3204(u32 *p, u32 b, u32 c)
{
    int n = func_0200BCB8(p[2]);
    u32 m = (u32)func_0201AB28((void *)b, c);

    if (n < 2) {
        func_021C3248();
        func_021C3250((void *)m);
        func_0200BC4C((struct Obj *)p[2], n, (const struct Payload *)m);
        func_0201A9C8((struct Party *)b, c);
        func_021C38DC(p[1], b);
    }
}
