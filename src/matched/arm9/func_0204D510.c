/*
 * function: CLACT_ResetAnim
 * address:  0x0204D510
 * packet:   pkt_0204D4B0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Closes the clact.c fan-in-1 blocker documented in
 * docs/notes/clact_c_fan_in_1_blockers.c.txt: CLACT_RestartActorAnim (its only
 * caller image wide) forwards its argument unchanged.
 *
 * Dispatch through a function-pointer table indexed by the mode word at
 * +0x00 of the argument; the call itself is an indirect `blx` (no PC24
 * relocation to attest), but the table base at 0x020A7F48 is an ABS32
 * literal with no second reference anywhere in the ARM9 image, so this
 * stays MATCH regardless of the C.
 *
 * symbols:
 *   g_ClactAnimResetFuncs  0x020A7F48  data
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/CLACT_ResetAnim.c \
 *       --func CLACT_ResetAnim --addr 0x0204D510 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct Ctl {
    u32 mode;  /* 0x00 */
};

typedef void (*Handler)(struct Ctl *c);

extern Handler g_ClactAnimResetFuncs[];

void CLACT_ResetAnim(struct Ctl *c)
{
    g_ClactAnimResetFuncs[c->mode](c);
}
