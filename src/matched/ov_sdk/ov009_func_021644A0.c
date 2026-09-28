/*
 * function: get48bits_3
 * address:  0x021644A0
 * packet:   pkt_ov009_021644A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
*/

asm void get48bits_3(void)
{
	ldrh r1, [r0]
	ldrh r2, [r0, #-2]
	ldrh r3, [r0, #-4]
	orr r0, r3, r2, lsl #16
	bx lr
}

