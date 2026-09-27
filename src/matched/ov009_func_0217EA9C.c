/*
 * function: gsiMemoryCallbacksSet
 * address:  0x0217EA9C
 * packet:   pkt_ov009_0217EA9C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   d_021A3730                   0x021A3730  data
*/

extern unsigned char d_021A3730[];

asm void gsiMemoryCallbacksSet(void)
{
	ldr ip, =d_021A3730
	stmia ip, {r0, r1, r2}
	str r3, [ip, #0xc]
	bx lr
}

