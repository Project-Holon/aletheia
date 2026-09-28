/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x02007428
 * packet:   pkt_02006E40
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02007428
 *
 * symbols:
 *   func_02033478  0x02033478  arm
 *
 * The last function of "save_control.c": two four byte writes of zero, to
 * 0x0007F800 and 0x0007FC00, through the ARM func_02033478.  Those two
 * constants are plain integer pool words with no relocation on them at all,
 * so they are written as the constants they are rather than declared in the
 * `symbols:` block, and the zero is one stack word whose address is passed
 * to both calls.
 *
 * func_02033478 is named three times in the whole image: by the two `blx`
 * sites inside this function and by one `blx` at 0x021DFF42 in ov228.  That
 * overlay branch is the only thing that carries it, because both in-region
 * sites are inside any range that contains this function and the honesty
 * rule discards them; the cross-region index is what makes it a `label`.
 * Without it this function would be in the same position as 0x02007374 and
 * 0x020073B0 and would not be matchable at all.
 *
 * The only caller of this function anywhere is the `bl` at 0x02007178 inside
 * sub_02007168, which is itself left out (its callee 0x02031BB4 is named
 * once, by the `blx` inside it), so nothing here depends on that direction.
 */

typedef unsigned int u32;

extern void func_02033478(u32 addr, const void *src, u32 size);

void sub_02007428(void)
{
    u32 zero = 0;

    func_02033478(0x7F800, &zero, 4);
    func_02033478(0x7FC00, &zero, 4);
}
