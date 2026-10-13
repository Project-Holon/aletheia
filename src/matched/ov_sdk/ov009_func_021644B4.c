/*
 * function: get64bits
 * address:  0x021644B4
 * packet:   pkt_ov009_021644B4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      get64bits (libssl.TWL.HYB.a(biginteger.o))
 * asm:      hand-written in the object: its .debug_line gives one row per
 *           instruction on consecutive source lines 324-330 and the DWARF
 *           subprogram has no variables; compiled C in the same object
 *           (CPSi_big_sign 47-54, CPSi_big_compare 177-183) spreads and
 *           reorders lines.  Siblings get48bits_2 and get48bits_3 read the same way.
 *
 * symbols:
 */

/* hand-written in the original: biginteger.o (libssl) asm routine, one debug row per instruction and no DWARF locals; no C spelling gives the bare lsl */
asm void get64bits(void)
{
	ldrh r2, [r0]
	ldrh r3, [r0, #-2]
	orr r1, r3, r2, lsl #16
	ldrh r2, [r0, #-4]
	ldrh r3, [r0, #-6]
	orr r0, r3, r2, lsl #16
	bx lr
}
