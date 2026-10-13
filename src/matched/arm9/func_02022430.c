/*
 * function: WIPE_SYS_InitPanel
 * address:  0x02022430
 * packet:   pkt_02022174
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The eleven-argument screen descriptor builder func_0202208C runs twice, once
 * per screen: a pure field-by-field copy of the argument list into the 0x26
 * byte sub-object, with no validation at all.  The four register arguments
 * land at +0x00..+0x0C and the seven stacked ones at +0x10..+0x24.
 *
 * Two shape facts the encoding pins down.  The sixth and seventh arguments are
 * stored the other way round from the argument order, +0x14 before +0x10, so
 * the struct's own field order is not the parameter order; writing them in
 * parameter order and letting the scheduler interleave is what reproduces the
 * ldr/str pairing.  The last argument is a u16, not a pointer: it is read back
 * with `add r1, sp, #0` + `ldrh r1, [r1, #0x18]` because Thumb has no
 * halfword load with an sp base, and stored with `strh`.  That is the value
 * WIPE_SUB_ResolveColor resolved, so the sentinel slot at +0x150 is a u16 end to end.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SYS_InitPanel.c \
 *       --func WIPE_SYS_InitPanel --addr 0x02022430 --cc 1.1p1 --thumb
 */
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Screen {
    u32   f00;
    u32   f04;
    s32   f08;
    u32   f0C;
    u32   f10;
    u32   f14;
    void *f18;
    void *f1C;
    u32   f20;
    u16   f24;
};

void WIPE_SYS_InitPanel(struct Screen *s, u32 a, u32 b, s32 c, u32 d, u32 e,
                   u32 f, void *g, void *h, u32 i, u16 j)
{
    s->f00 = a;
    s->f04 = b;
    s->f08 = c;
    s->f0C = d;
    s->f14 = e;
    s->f10 = f;
    s->f18 = g;
    s->f1C = h;
    s->f20 = i;
    s->f24 = j;
}
