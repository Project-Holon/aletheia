/*
 * function: func_021D4B60
 * address:  0x021D4B60
 * packet:   pkt_ov016_021D4B60
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      cbWrite (libdwcutil.TWL.HYB.a(archive.o))
 *
 * notes:    `mov r0, #1; bx lr`; DWCi_ARClInit's relocation at +0x1AC (ABS32 cbWrite)
 *           is the pool word at 0x021D4A18.  Seeded in layout/function_starts.txt.
 */

int func_021D4B60(void)
{
    return 1;
}
