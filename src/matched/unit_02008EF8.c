/*
 * Matched game function, written from the disassembly in
 * asm/arm9/src/001_02007664.s.  Not an SDK symbol: it is absent from
 * layout/symbols_sdk.txt.
 *
 * unit:     yes
 * address:  0x02008EF8
 * function: sub_02008EF8
 * packet:   pkt_02008A34
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Original (14 bytes, leaf, no relocations):
 *   ldrb r0, [r0, #7]
 *   cmp  r0, #0xb
 *   bhi  0x2008f02
 *   movs r0, #1
 *   bx   lr
 *   movs r0, #0
 *   bx   lr
 *
 * The range predicate on the byte at +7 of the 0x38-byte object described in
 * src/matched/unit_02008F80.c: the setter there refuses anything at or past
 * 0xC, and this answers whether the field is inside that range.  `bhi` rather
 * than `bgt` is the only evidence that the comparison is unsigned; the field is
 * loaded with `ldrb` either way.
 *
 * The taken arm is the zero, so the source tests the in-range case and returns
 * 1 by falling through.
 *
 * Recorded as a one-function byte range rather than as a function entry
 * because the function ends at 0x02008F06 and the next label is at 0x02008F08:
 * two bytes of inter-section fill sit between them, so the extent disasm.py
 * infers runs two bytes long and a function entry would read EXACT*.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02008EF8.c  *       --addr 0x02008EF8 --thumb
 */

typedef unsigned char u8;

struct Sub02008F80Obj {
    u8 unk00[7];
    u8 unk07;
};

int sub_02008EF8(const struct Sub02008F80Obj *obj)
{
    if (obj->unk07 <= 0xB) {
        return 1;
    }
    return 0;
}
