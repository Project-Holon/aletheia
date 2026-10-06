/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x02033C9C
 * packet:   pkt_020339D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: sub_02033C9C
 *
 * Four to eight byte function with no prologue at all: a pool word and a
 * bx, exactly the tail-call veneer idiom recorded in
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md. No arguments are touched,
 * so the call forwards whatever the caller left in the argument registers.
 *
 * symbols:
 *   func_020307B0   0x020307B0   arm
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02033C9C.c \
 *       --addr 0x02033C9C --arm
 */

typedef unsigned int u32;

extern u32 func_020307B0(void *p);

u32 sub_02033C9C(void *a, u32 b, u32 c, u32 d)
{
    return func_020307B0(a);
}
