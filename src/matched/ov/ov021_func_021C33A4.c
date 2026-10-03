/*
 * function: func_021C33A4
 * address:  0x021C33A4
 * packet:   pkt_ov021_021C33A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sets event flag 0x4139 when the party is not full.
 *
 * symbols:
 *   func_02188C80  0x02188C80  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_02188C80(void *p);
struct BigObj;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_0201296C(void *p);
extern void *func_02012934(const struct BigObj *p);
extern u32 func_0201AA18(void *p);
extern int func_0201AA14(void *p);
extern u16 *func_020143CC(void *p, int id);

void func_021C33A4(void *a)
{
    void *g = func_020120F4(func_02188C80(a));
    void *ev = func_0201296C(g);
    void *party = func_02012934(g);

    if ((int)func_0201AA18(party) < func_0201AA14(party))
        *func_020143CC(ev, 0x4139) = 1;
}
