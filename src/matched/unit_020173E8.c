/*
 * unit:     yes
 * address:  0x020173E8
 * packet:   pkt_02016FC8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_020173E8, func_020173EC
 *
 * The two record sizes this region's files open with, `movs r0, #imm; bx lr`,
 * neither of them labelled in the generated listing because neither saves lr.
 * 0xDC is exactly what func_02017528 in src/matched/unit_02017528.c clears and
 * 0x88 exactly what func_02017550 clears, so the two constants and the struct
 * declaration check each other.  See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * The three functions in front of them are parked in
 * src/pending/unit_020173B4.c.
 *
 * The original file name of the two constructors after them is recoverable
 * even though neither is matched yet: func_020173F0 and func_02017430 both
 * pass 0x020A72E4 to the debug allocator at 0x02030734, and the bytes there
 * spell "poke_tool.c".  Its left neighbours in the packed string area are
 * "d_status.c" at 0x020A72C0 and "mcss.c" at 0x020A72CC, and between "mcss.c"
 * and it sit four pointer words at 0x020A72D4, so the `string` class cannot
 * reach it (docs/idioms/a-string-after-a-data-table-has-no-witness.md).  The
 * `literal` class can: two pool words name it, 0x0201742C and 0x02017478, so
 * a range holding exactly one of the two constructors attests it.  Neither is
 * matched here because each is in turn the only caller of its worker.
 */

typedef unsigned int u32;

u32 func_020173E8(void)
{
    return 0x88;
}

u32 func_020173EC(void)
{
    return 0xDC;
}
