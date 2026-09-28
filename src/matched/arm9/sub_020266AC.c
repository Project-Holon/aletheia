/*
 * unit:     no
 * address:  0x020266AC
 * packet:   pkt_02026250
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_020266AC
 *
 * symbols:
 *   sub_02026504  0x02026504  thumb
 *
 * A thin wrapper over `sub_02026504` (258 bytes, still open), forwarding
 * its three arguments unchanged and appending a fourth: 0x27 when the
 * second and third arguments are equal, 0x26 otherwise. The `? :` form,
 * not an `if`/`else` writing the call twice, is what reproduces the
 * single shared `lsls`/`lsrs #0x10` that narrows the chosen constant to
 * the callee's 16-bit fourth parameter after the branch instead of in
 * each arm.
 *
 * `sub_02026504`'s only three callers in the whole ARM9 image are this
 * function and its two siblings sub_020266C0 and sub_020266D4
 * (src/matched/sub_020266C0.c, src/matched/sub_020266D4.c). Keeping each
 * in its own translation unit is what gives the other two's calls
 * standing as outside evidence for this one; compiled together as a
 * single unit the three calls would attest only each other and the whole
 * range would cap at MATCH (docs/MATCHING.md, "the pairwise case across
 * two files").
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020266AC.c \
 *       --func sub_020266AC --addr 0x020266AC --cc 1.1p1 --thumb
 */

typedef unsigned int u32;
typedef unsigned short u16;

extern void sub_02026504(u32 a, u32 b, u32 c, u16 d);

void sub_020266AC(u32 a, u32 b, u32 c)
{
    sub_02026504(a, b, c, (b == c) ? 0x27 : 0x26);
}
