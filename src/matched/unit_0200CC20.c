/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 * unit:     yes
 * address:  0x0200CC20
 * packet:   pkt_0200CA98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0200CC20
 *
 * 32 bytes, 0x0200CC20..0x0200CC40, one function, which carries a label in the
 * generated listing.
 *
 * The table at 0x0209DE4C is a run of `{u16 form; u16 count;}` pairs: this
 * function returns the count for a form group and func_0200CA98 walks the same
 * array looking for the first pair whose first halfword matches.  The stride is
 * four, which is the `lsls #2` here and in func_0200CA98, so the two halfwords
 * are one record and not two parallel arrays; the pool word for the second
 * field is the symbol plus two rather than a second symbol.
 *
 * The branch that answers 1 is the `else`, so the table lookup is the source's
 * `then`: written the other way round, as a guard returning 1 first, the
 * condition inverts and the two arms swap.  See
 * docs/idioms/the-fall-through-arm-is-the-source-order.md.
 *
 *
 * Two near misses in the same original file, recorded here because this is the
 * matched file next to them.
 *
 * func_0200CA98, 376 bytes at 0x0200CA98, the bit-array maintenance this
 * table drives.  It comes out four bytes short of 392 with the right control
 * flow throughout: mwccarm hoists the two loop-invariant bitmap pointers above
 * the loop's own entry test, where the original computes them in the loop
 * preheader and reloads the block pointer from its spill slot once for each of
 * them, and it hoists `m + (id >> 3)` out of the four-iteration clearing loop,
 * where the original forms `m + i * 0x54` first and leaves the byte index as
 * the load's register operand.  Both are the same choice of which half of an
 * address expression to make loop-invariant, and neither moved under any of the
 * shapes tried: the two pointers as locals assigned before the loop, assigned
 * inside it and written out inline; the loop as `for`, as `do`/`while` and
 * behind an explicit `if (n != 0)` guard; the mask operands in both orders; and
 * the row index through a `u8 (*)[0x54]` local, through the struct member and
 * through a flat offset.
 *
 * func_0200CC40, 402 bytes at 0x0200CC40, the query that reads the same three
 * bitmap groups back.  Its first half reproduces instruction for instruction;
 * its second half, four independent `if`s that each test one bitmap and write
 * two out-parameters, does not, because the original recomputes the shift, the
 * mask and the base address inside every one of the four blocks and mwccarm
 * computes them once in the dominating block and reuses them.  That is 52 bytes
 * of common subexpressions the original does not share, and writing the
 * expressions out in full in each block does not restore them.
 *
 * symbols:
 *   func_0200CA98_Table  0x0209DE4C  data
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct FormCount {
    u16 unk00;
    u16 unk02;
};

extern const struct FormCount func_0200CA98_Table[];

extern s32 func_0200C7F4(u32 a);

u16 func_0200CC20(u32 a)
{
    s32 i = func_0200C7F4(a);

    if (i != -1) {
        return func_0200CA98_Table[i].unk02;
    }
    return 1;
}
