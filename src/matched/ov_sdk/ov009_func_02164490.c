/*
 * function: get48bits_2
 * address:  0x02164490
 * packet:   pkt_ov009_02164490
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      get48bits_2 (libssl.TWL.HYB.a(biginteger.o))
 * asm:      hand-written in the object: its .debug_line gives one row per
 *           instruction on consecutive source lines 309-312 and the DWARF
 *           subprogram has no variables; compiled C in the same object
 *           (CPSi_big_sign 47-54, CPSi_big_compare 177-183) spreads and
 *           reorders lines.  No C spelling gives the bare `lsl` (w4_nm: `orr #0`
 *           or `adds/adc`).
 *
 * symbols:
 */

asm void get48bits_2(void)
{
	ldrh r1, [r0]
	ldrh r0, [r0, #-2]
	mov r0, r0, lsl #16
	bx lr
}
