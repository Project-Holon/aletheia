/*
 * function: CLACT_IsVramTypeCompatible
 * address:  0x0204D9B4
 * packet:   pkt_0204D768
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Two-value compatibility test: value 2 is the wildcard, otherwise the two
 * have to be equal.  A leaf, no relocation.
 *
 * The disjunction has to be one expression so that both halves share the
 * `moveq r0, #1` / `bxeq lr` exit
 * (docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md); the
 * second test is the predicated `cmpne r1, #2`, which is what a `||` looks
 * like once it is short enough not to branch.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_IsVramTypeCompatible.c \
 *       --func CLACT_IsVramTypeCompatible --addr 0x0204D9B4 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

u32 CLACT_IsVramTypeCompatible(u32 a, u32 b)
{
    if (a == 2 || b == 2) {
        return 1;
    }
    return a == b;
}
