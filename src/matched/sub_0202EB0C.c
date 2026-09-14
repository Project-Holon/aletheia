/*
 * unit:     no
 * function: sub_0202EB0C
 * address:  0x0202EB0C
 * packet:   pkt_0202E770
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02085D3C  0x02085D3C  arm
 *
 * A pool-word-and-bx tail call into an ARM SDK entry point
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md), eight bytes with no
 * prologue. Its result is compared against 1 by src/matched/sub_0202EB4C.c,
 * which is the only caller.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202EB0C.c \
 *       --func sub_0202EB0C --addr 0x0202EB0C --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern u32 func_02085D3C(void);

u32 sub_0202EB0C(void)
{
    return func_02085D3C();
}
