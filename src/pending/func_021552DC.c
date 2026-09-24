/*
 * function: func_021552DC
 * address:  0x021552DC
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Returns three less the word func_0205CCD8 returns.
 *
 * blocking: the only relocation is the blx at +0002, to 0x0205CCD8.  That
 * address has no witness: it is not in the arm9 matched set and the arm9
 * listing carries no label there (the disassembler emitted that block as
 * data), so the site stays wildcarded and the entry caps at MATCH.  Every
 * other byte of the 12 is identical.  The 0x0205CCD8 symbol itself is in
 * layout/symbols_sdk.json, which is why the call resolves by name at all.
 *
 * symbols:
 *   func_0205CCD8  0x0205CCD8  thumb
 */

extern int func_0205CCD8(void);

int func_021552DC(void)
{
    return 3 - func_0205CCD8();
}
