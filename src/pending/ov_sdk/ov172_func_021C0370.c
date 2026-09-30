/*
 * function: func_021C0370
 * address:  0x021C0370
 * packet:   pkt_ov172_021C0370
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * w9_nm: 27 B -> 7 B: `word = (unsigned short)src[cur] | word;` in the little-endian arm makes
 * the big-endian arm byte-identical (branches, not predication, in both arms). Left: the
 * little-endian arm wants zext(word) as the first orr operand and the byte shifted
 * (`lsl r0,r3,#16 ... orr r0,r1,r0,lsr #16`); this compile has the byte plain and the word
 * Tried: 14 spellings (locals u16, casts, return forms, else nesting, |= vs =, operand order).
 *
 * Lane U38 (2026-09-30): 26 further spellings of the little-endian arm, still
 * stuck at 7 concrete bytes (the arm at +0008..+002C only; the big-endian arm
 * at +0030 is byte-identical).  Tried: casts on either/both operands, the
 * one-statement forms `word = (u16)A | (u16)B;` (16) and `word = A | B;` (40),
 * two-statement forms with `|=`, `word = word | B`, `word = (u16)(word | B)`,
 * intermediate u16 locals for either operand, `+` instead of `|` (8), and
 * `& 0xff00` spelled at the end (49).  What the image does and no spelling
 * reaches: it narrows BOTH operands to u16 with separate shifts --
 * `lsl r1, r0, #0x10` / `lsr r1, r1, #0x10` on the masked byte, and
 * `lsl r0, r3, #0x10` with the `lsr #16` folded into the `orr` for the other
 * byte -- so the loaded byte lands in r3 (`ldrb r3, [r0, r1]`) and nothing is
 * truncated after the `orr`.  Every spelling mwcc accepts instead folds one
 * operand and truncates the result: `orr r0, r1, r0, lsr #16` followed by
 * `lsl r0, r0, #0x10` / `lsr r0, r0, #0x10`.  First divergence +0010
 * image `ldrb r3, [r0, r1]` | ours `ldrb r1, [r0, r1]`.
 *
 * sdk:      GetWord (exifdec.o)
 *
 * symbols:
 *   (none)
 */

unsigned short func_021C0370(unsigned char *src, unsigned long cur, short Endian)
{
    unsigned short word;

    if (Endian == 0) {
        word = (src[cur + 1] << 8) & 0xff00;
        word = (unsigned short)src[cur] | word;
        return word;
    }
    word = (src[cur] << 8) & 0xff00;
    word |= src[cur + 1];
    return word;
}
