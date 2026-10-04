/*
 * function: sub_02014CF8
 * address:  0x02014CF8
 * packet:   pkt_02014444
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02016BA0  0x02016BA0  thumb
 *   func_020163C4  0x020163C4  thumb
 *
 * Prepares b (a validation call, func_02016BA0), copies a 0x24-byte record
 * from c into b's field at +0x150 (the inlined ldm/stm loop plus one trailing
 * word is docs/idioms/aggregate-assignment-is-ldm-stm.md), then forwards a,
 * a pointer field of b at +0x148, and the original record pointer c to
 * func_020163C4.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02014CF8.c \
 *       --func sub_02014CF8 --addr 0x02014CF8 --thumb --cc 1.1p1
 */

typedef unsigned int u32;

struct Sub02014CF8Rec {
    u32 w[9];
};

struct Sub02014CF8Ctx {
    u32                    pad000[(0x148 - 0) / 4];
    void                  *f148;
    u32                    pad14C;
    struct Sub02014CF8Rec  f150;
};

extern void func_02016BA0(void *obj);
struct Ctx;
struct Src;
extern void func_020163C4(struct Ctx *a0, u32 idx, const struct Src *a2);

void sub_02014CF8(void *a, struct Sub02014CF8Ctx *b, const struct Sub02014CF8Rec *c)
{
    func_02016BA0(b);
    b->f150 = *c;
    func_020163C4(a, (u32)b->f148, (const struct Src *)((struct Sub02014CF8Rec *)c));
}
