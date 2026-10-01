/*
 * function: func_021C0370
 * address:  0x021C0370
 * packet:   pkt_ov172_021C0370
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * lane03 (2026-09-30): re-verified under the wave-7 command; it is DIFF, not MATCH -- 0
 * relocation sites and 7 concrete bytes differ, all in the little-endian arm.  The
 * compiler is exactly 4.0.0.1024 (1.1p1), so this is a codegen gap and not a stamp
 * issue: the image narrows BOTH orr operands into separate temps (`lsl r1,r0,#16;
 * lsl r0,r3,#16; lsr r1,r1,#16; orr r0,r1,r0,lsr #16`, low byte in r3), while every
 * source spelling 1.1p1 accepts folds one operand and masks the result (`orr r0,r1,
 * r0,lsr #16; lsl r0,r0,#16; lsr r0,r0,#16`, low byte in r1).  The adjacent GetLong
 * (0x021C03C0, EXACT) and the one-arm gti2UShortFromBuffer (0x02195E80, EXACT) confirm
 * the BE arm is right; only the LE arm's operand narrowing differs.  ~120 spellings
 * tried this lane (casts on either/both operands, high-first/low-first, int/u16/int
 * temporaries, volatile src, masks, +=/|, two- and three-statement forms) plus
 * tools/permute.py and tools/permuter.py hill runs; none move the 7 bytes.
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
 * wave8 (2026-09-30): re-confirmed 7 concrete B, unchanged. Added spellings: the
 * 32-bit-context forms `word = (unsigned short)((src[cur+1]<<8)&0xff00) | (unsigned short)src[cur];`
 * and `(unsigned short)(word | src[cur])`, the separate `unsigned short hi/lo` locals, and the
 * one-statement `word = ((src[cur+1]<<8)&0xff00) | src[cur];` (the last is 76 B / worse). Every
 * spelling mwcc accepts canonicalises to the same node and folds the LE orr to `zext16(byte|word)`;
 * the image keeps the two u16 conversions distinct (`zext16(word)` as the orr's plain operand and
 * `byte<<16` folded into the shifted slot). Image loads the byte into r3, ours into r1: a node/
 * allocator identity residue, not an unspelled body. No new general lever found.
 *
 * lane wave8 (2026-10-01): 42 more LE-arm spellings, still exactly 7 concrete B.
 * Tried: both operand orders in every form, explicit `(unsigned short)`/`(short)`
 * casts on one/both operands, a separate `int`/`u16` hi local, an outer
 * `(unsigned short)(...)` over the OR, `(unsigned char)` and `(unsigned short)`
 * byte casts, and the sibling 0x021C3A28 `(short)`-cast idiom
 * (docs/idioms/a-short-cast-makes-a-masked-byte-shift-unwidened.md). Every spelling
 * mwcc accepts canonicalises `(u16)word | (u16)byte` into `(u16)(word | byte)`, so it
 * folds the *word* cast into the orr and re-truncates the result; the image keeps the
 * word cast materialised (`lsl r1,r0,#16; lsr r1,r1,#16`) and folds the *byte*
 * (`lsl r0,r3,#16; orr r0,r1,r0,lsr #16`). This is the documented closed class
 * docs/idioms/a-materialised-shift-temporary-is-not-reachable-from-c-or-from-flags.md:
 * same instruction count, same registers, only which operand receives the standalone
 * cast pair differs -- an instruction-selection/allocator tie below the source text,
 * with no third use of the masked value to force it out of the shifter operand
 * (80-byte leaf). See also docs/idioms/the-accumulator-of-a-commutative-chain-is-its-second-operand.md.
 *
 * blocker:  LE arm's u16-cast selection: image materialises zext16(word) and folds
 *           zext16(byte); 1.1p1 canonicalises both casts into one and folds the word
 *           instead. Not reachable from C (closed idiom); 0 relocs.
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
