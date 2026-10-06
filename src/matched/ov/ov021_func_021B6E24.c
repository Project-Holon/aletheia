/*
 * function: func_021B6E24
 * address:  0x021B6E24
 * packet:   pkt_ov021_021B6E24
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_0216D598  0x0216D598  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned char  u8;
extern void *func_02188C7C(u8 *p);
typedef unsigned int   u32;
struct Ctx;
struct Rec;
extern int func_0216DD1C(struct Ctx *c, struct Rec **out, u32 *iter);
extern u16 func_0216D598(void *p);

void *func_021B6E24(void *a)
{
    unsigned long it = 0;
    void *rec;
    void *list;

    list = func_02188C7C(a);
    while (func_0216DD1C(list, (struct Rec **)(&rec), (u32 *)(&it)) == 1) {
        if (func_0216D598(rec) == 0x46)
            return rec;
    }
    return 0;
}
