/*
 * function: func_021C32BC
 * address:  0x021C32BC
 * packet:   pkt_ov021_021C32BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns the Pokemon's held item to the bag when it fits.
 *
 * symbols:
 *   func_02188C80  0x02188C80  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_02188C80(void *p);
struct Blk37;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_0200CA1C(void *p);
extern u32 func_0200CED4(struct Blk37 *p, u16 id);
extern void func_0200CDE0(struct Blk37 *p, void *m);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);

void func_021C32BC(void **p, void *mon)
{
    void *bag = func_0200CA1C(func_020120F4(func_02188C80(p[1])));

    if (func_0200CED4(bag, func_02017E1C(mon, 5, 0)) == 0)
        func_0200CDE0(bag, mon);
}
