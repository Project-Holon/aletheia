/*
 * function: func_021C4678
 * address:  0x021C4678
 * packet:   pkt_ov021_021C4678
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Refreshes the field object from the day-care state (EXACT*: pad).
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021C9550  0x021C9550  thumb  ov021
 */

typedef unsigned int u32;

extern void *func_0215A5DC(void *a0);
typedef unsigned char  u8;
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
struct Obj00020;
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(unsigned char *p);
extern u32 func_02188CD0(u8 *p);
extern void func_021C9550(u32 a, u32 b);

int func_021C4678(void *a, void *b)
{
    void *g = func_0201210C(func_0215A5DC(b));
    void *h = func_021A3074(func_02188CB4((void *)g));

    func_021C9550((u32)h, func_02188CD0(g));
    return 0;
}
