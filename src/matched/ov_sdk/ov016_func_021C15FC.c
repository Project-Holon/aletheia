/*
 * function: cbConfig
 * address:  0x021C15FC
 * packet:   pkt_ov016_021C15FC
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
*/

asm void cbConfig(void)
{
	ldr r3, =0x021DE594
	ldmia r0, {r0, r1, r2}
	ldr r3, [r3]
	stmia r3, {r0, r1, r2}
	bx lr
}

