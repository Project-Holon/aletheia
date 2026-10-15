/*
 * unit:     no
 * function: GF_STANDARD_Shuffle
 * address:  0x0203F328
 * packet:   pkt_0203EF5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GF_STANDARD_RandLcg  0x0203F388  arm
 *
 * TU: gf_standard.c.
 *
 * XOR a halfword buffer against the LCG stream seeded by the third
 * argument.  The function really starts at 0x0203F328, not at the
 * 0x0203F32C that disasm.py labels: the first word is `push {r0,r1,r2,r3}`,
 * the home area that taking `&seed` forces, and the matching `add sp, sp,
 * #0x10` is what makes the epilogue pop lr and then `bx lr` instead of
 * popping pc.  `seed` lives at sp+0x20 once both pushes are done.
 *
 * EXACT*, not EXACT: disasm.py labels 0x0203F32C, so the inferred extent
 * for 0x0203F328 is the single `push {r0,r1,r2,r3}` word; the real function
 * is 0x0203F328-0x0203F37C.  0x0203F328 wants seeding into
 * layout/function_starts.txt and 0x0203F32C wants removing from it.
 *
 * GF_STANDARD_RandLcg has exactly one caller image-wide, this one, so its only
 * route to a witness is its own manifest entry in this same shard; the
 * first `manifest --verify` after adding both files leaves this one at
 * MATCH* and the second promotes it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_STANDARD_Shuffle.c \
 *       --func GF_STANDARD_Shuffle --addr 0x0203F328 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 GF_STANDARD_RandLcg(u32 *seed);

void GF_STANDARD_Shuffle(u16 *p, u32 size, u32 seed)
{
    u32 i;
    u32 n = size >> 1;

    for (i = 0; i < n; i++) {
        p[i] ^= GF_STANDARD_RandLcg(&seed);
    }
}
