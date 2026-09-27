/*
 * function: DWCi_TSKlForm
 * address:  0x021D7680
 * packet:   pkt_ov016_021D7680
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   formTask                     0x021D7694  arm
*/

extern void formTask(void);

asm void DWCi_TSKlForm(void)
{
	stmdb sp!, {r3, lr}
	mov ip, #0
	str ip, [sp]
	bl formTask
	ldmia sp!, {r3, pc}
}

