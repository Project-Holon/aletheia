/*
 * Matched game function, written from the disassembly in
 * asm/arm9/src/002_02009750.s.  This is the function docs/MATCHING.md used
 * to record as a near miss; it is a match now, and what changed is one
 * declaration.
 *
 * function: sub_0200A6BC
 * address:  0x0200A6BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Original (60 bytes, leaf, no relocations):
 *   push {r4, r5}
 *   cmp  r1, #0x64
 *   bhs  .out
 *   lsrs r5, r1, #0x1f      ; the signed % 8 sequence
 *   lsls r4, r1, #0x1d
 *   subs r4, r4, r5
 *   movs r3, #0x1d
 *   rors r4, r3
 *   adds r3, r5, r4
 *   lsls r3, r3, #0x18      ; sh truncated to u8 before the shift
 *   lsrs r4, r3, #0x18
 *   movs r3, #1
 *   lsls r3, r4             ; 1 << sh
 *   movs r4, #0x96
 *   lsls r1, r1, #0x15      ; idx = (u8)(n >> 3)
 *   lsls r3, r3, #0x18      ; the u8 truncation of 1 << sh, split ...
 *   lsls r4, r4, #2         ; 0x258
 *   lsrs r2, r1, #0x18
 *   adds r1, r0, r4
 *   ldrb r5, [r1, r2]
 *   lsrs r3, r3, #0x18      ; ... around the first load
 *   adds r4, #0x20          ; 0x278, reusing the first offset
 *   orrs r5, r3
 *   strb r5, [r1, r2]
 *   adds r1, r0, r4
 *   ldrb r0, [r1, r2]
 *   orrs r0, r3
 *   strb r0, [r1, r2]
 *  .out:
 *   pop  {r4, r5}
 *   bx   lr
 *
 * Set one bit, at the same position, in each of two 0x20-byte bitmaps that
 * sit next to each other inside a large structure, for an index checked
 * against 100 (0x64, so 100 of the 256 bits are in use).  The two bitmaps are
 * at 0x258 and 0x278; the second offset is the first plus 0x20, which is what
 * the `adds r4, #0x20` is, and it is only that cheap because the compiler
 * kept the first offset live in a register.
 *
 * Four details pin the source shape, in decreasing order of how long they
 * took to find:
 *
 *  1. `1 << sh` must NOT be held in a u8 temporary, and the truncation to a
 *     byte must be written at the point of use.  With `u8 bit = 1 << sh;` the
 *     truncation happens once, immediately, and the whole tail reschedules:
 *     the same eighteen instructions in a different order, every general
 *     register shifted by one, 31 concrete bytes wrong.  Written at the uses
 *     and left to common subexpression elimination, the truncation instead
 *     sinks, which is what splits the `lsls #24` / `lsrs #24` pair around the
 *     first ldrb.  That split pair is the visible signature of the right
 *     shape.  The cast has to be explicit rather than left to the implicit
 *     conversion in `|=`: with `|= 1 << shift` the two front ends disagree,
 *     build 1018 (dsi/1.1) dropping the truncation and emitting 56 bytes
 *     while build 1024 and later keep it and emit 60.  Written as it is here
 *     all nine front ends agree, which is why this form is the one committed.
 *  2. the guard is an unsigned compare (`cmp #0x64` / `bhs`) even though the
 *     index is otherwise signed, so it is written against an unsigned
 *     parameter.  As `if (n < 0 || n >= 100)` on a signed parameter this
 *     compiler emits two compares and two branches instead of folding them.
 *  3. the same value is `% 8` in one place and `>> 3` in another.  `% 8` on a
 *     signed value compiles to the `lsrs #31` / `lsls #29` / `subs` / `rors
 *     #29` sequence the original shows; `& 7` would be a two-instruction
 *     `movs`/`ands`, and `/ 8` would add a rounding correction the original
 *     does not have.
 *  4. the shift amount is truncated to u8 before the shift, not after.  That
 *     intermediate is the `lsls #24` / `lsrs #24` pair between the modulo and
 *     the `movs r3, #1`.
 *
 * The verdict used to be EXACT* rather than EXACT because the function at
 * 0x0200A6F8 carried no label in the generated listing: its prologue is
 * `push {r3, r4}`, with no lr to save, so disasm.py's prologue sweep did not
 * fire, and its only caller is in ov133.  The inferred extent for this
 * function therefore ran 88 bytes, to the next label at 0x0200A714.
 * 0x0200A6F8 is now in layout/function_starts.txt, attested by the bl at
 * 0x021B62A2, and the extent is the 60 bytes this file compiles.
 */

typedef unsigned char u8;
typedef unsigned int  u32;
typedef signed int    s32;

struct Sub0200A6BCObj {
    u8 unk000[0x258];
    u8 unk258[0x20];
    u8 unk278[0x20];
};

void sub_0200A6BC(struct Sub0200A6BCObj *obj, u32 index)
{
    u8 shift, byte;

    if (index >= 100) {
        return;
    }
    shift = (s32)index % 8;
    byte  = index >> 3;
    obj->unk258[byte] |= (u8)(1 << shift);
    obj->unk278[byte] |= (u8)(1 << shift);
}
