/*
 * function: DWCi_FNTlClear
 * address:  0x021D5F14
 * packet:   pkt_ov016_021D5F14
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
*/

asm void DWCi_FNTlClear(void)
{
	stmdb sp!, {r3, lr}
	ldr r2, [r0, #0x14]
	ldr r2, [r2, #4]
	blx r2
	ldmia sp!, {r3, pc}
}

