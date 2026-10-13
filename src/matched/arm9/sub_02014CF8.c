/*
 * function: MCSS_ReloadResource
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
 *   MCSS_FreeResource  0x02016BA0  thumb
 *   MCSS_LoadResource  0x020163C4  thumb
 *
 * Prepares b (a validation call, MCSS_FreeResource), copies a 0x24-byte record
 * from c into b's field at +0x150 (the inlined ldm/stm loop plus one trailing
 * word is docs/idioms/aggregate-assignment-is-ldm-stm.md), then forwards a,
 * a pointer field of b at +0x148, and the original record pointer c to
 * MCSS_LoadResource.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MCSS_ReloadResource.c \
 *       --func MCSS_ReloadResource --addr 0x02014CF8 --thumb --cc 1.1p1
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

extern void MCSS_FreeResource(void *obj);
struct Ctx;
struct Src;
extern void MCSS_LoadResource(struct Ctx *a0, u32 idx, const struct Src *a2);

void MCSS_ReloadResource(void *a, struct Sub02014CF8Ctx *b, const struct Sub02014CF8Rec *c)
{
    MCSS_FreeResource(b);
    b->f150 = *c;
    MCSS_LoadResource(a, (u32)b->f148, (const struct Src *)((struct Sub02014CF8Rec *)c));
}
