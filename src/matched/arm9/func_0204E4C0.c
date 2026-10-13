/*
 * function: TEXTPRINT_SjisToGlyphCode
 * address:  0x0204E4C0
 * packet:   pkt_0204E4C0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * A character-code remap: five contiguous Shift-JIS-style ranges relocated by
 * a constant delta, then four single codes mapped individually, with 0x0101
 * as the fallback.  No relocations at all; every one of the seven pool words
 * at 0x0204E5CC is material.
 *
 * The shape that reproduces it is the plain chain of `if (c >= base && c <=
 * base + n) return c + delta;` with BOTH constants written relative to the
 * same base: the compiler materialises `base` once per arm into r2 and
 * derives the upper bound as `add r1, r2, #n` and the delta as `rsb r1, r2,
 * #k` (or `sub` where the delta is negative), which is why the deltas here
 * are spelled `(4 - 0x829F)` rather than as their folded values.  Writing a
 * delta as a bare constant costs each arm its own pool word.
 *
 * The last group shares its base too: 0x8189 feeds `moveq r0, #0xcc`,
 * `add r1, r2, #1`, `sub r1, r2, #0x49` and `sub r1, r2, #0x2e`, so all four
 * single-code tests must be written against 0x8189, not as literals.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TEXTPRINT_SjisToGlyphCode.c \
 *       --func TEXTPRINT_SjisToGlyphCode --addr 0x0204E4C0 --cc 1.1p1 --arm
 */

typedef unsigned short u16;

u16 TEXTPRINT_SjisToGlyphCode(u16 c)
{
    if (c >= 0x829F && c <= 0x829F + 0x52)
        return c + (4 - 0x829F);
    if (c >= 0x8340 && c <= 0x8340 + 0x53)
        return c + (0x57 - 0x8340);
    if (c >= 0x8281 && c <= 0x8281 + 0x19)
        return c + (0xDA - 0x8281);
    if (c >= 0x8260 && c <= 0x8260 + 0x19)
        return c + (0x8260 - 0x10400);
    if (c >= 0x824F && c <= 0x824F + 9)
        return c + (0xAC - 0x824F);
    if (c == 0x8189)
        return 0xCC;
    if (c == 0x8189 + 1)
        return 0xC5;
    if (c == 0x8189 - 0x49)
        return 2;
    if (c == 0x8189 - 0x2E)
        return 0x51;
    return 0x0101;
}
