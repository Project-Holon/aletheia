/*
 * function: Parent_get_child_data_kind
 * address:  0x021D4854
 * packet:   pkt_ov016_021D4854
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
*/

asm void Parent_get_child_data_kind(void)
{
	ldr r0, =0x021DE668
	ldr r0, [r0]
	add r0, r0, #0x100
	ldrh r0, [r0, #0x44]
	bx lr
}

