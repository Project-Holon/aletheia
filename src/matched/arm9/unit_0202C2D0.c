/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0202C2D0
 * packet:   pkt_0202C244
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0202C2D0, sub_0202C2D8
 *
 * symbols:
 *   func_02005C44  0x02005C44  thumb
 *
 * sub_0202C2D0 is a pool-word-and-bx tail call
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md) forwarding into
 * func_02005C44, which is open elsewhere in the image. sub_0202C2D8 is a
 * plain read of the object's first word.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202C2D0.c \
 *       --addr 0x0202C2D0 --thumb
 */

typedef unsigned int u32;

typedef unsigned short u16;
extern u16 func_02005C44(void);

u32 sub_0202C2D0(u32 v)
{
    return func_02005C44();
}

u32 sub_0202C2D8(u32 *p)
{
    return *p;
}
