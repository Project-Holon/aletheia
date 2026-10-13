/*
 * function: DWCi_GdbSwitchWork
 * address:  0x021E214C
 * packet:   pkt_021E214C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gDwcGdbEntity   0x021E5334  data
 *
 * Leaf: flips the "active" word at +0x14 of the ov175 bss descriptor
 *     0x021E5334 between 0 and 1.  Written through the data symbol rather
 *     than as an integer constant: with the constant MWCC folds +0x14 into
 *     the pool word and swaps the base/value registers, and no spelling of
 *     the constant reaches the original encoding.
 */

typedef unsigned long u32;

extern u32 gDwcGdbEntity[];

void DWCi_GdbSwitchWork(void)
{
    if (gDwcGdbEntity[5] == 0)
        gDwcGdbEntity[5] = 1;
    else
        gDwcGdbEntity[5] = 0;
}
