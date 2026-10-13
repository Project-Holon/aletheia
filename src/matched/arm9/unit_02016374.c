/*
 * A single matched function.
 *
 * unit:     yes
 * address:  0x02016374
 * packet:   pkt_02015F2C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: MCSS_RestartAnime
 *
 * symbols:
 *   NNS_G2dRestartMCAnimation  0x02064CBC  arm
 *
 * alias: an argument-adjusting tail call: it shifts the object pointer to
 * a member 0x34 bytes in and hands off to NNS_G2dRestartMCAnimation. See
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/unit_02016374.c \
 *       --func MCSS_RestartAnime --addr 0x02016374 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;

struct Obj;
extern void NNS_G2dRestartMCAnimation(struct Obj *x);

void MCSS_RestartAnime(void *obj)
{
    NNS_G2dRestartMCAnimation((struct Obj *)((u8 *)obj + 0x34));
}
