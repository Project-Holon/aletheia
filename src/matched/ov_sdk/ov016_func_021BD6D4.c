/*
 * function: DWCi_HLlLoadSet
 * address:  0x021BD6D4
 * packet:   pkt_ov016_021BD6D4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SETTIGNlGet             0x021CF404  arm
 *   DWCi_HLlLoad                 0x021BD674  arm
*/

extern void DWCi_SETTIGNlGet(void);
extern void DWCi_HLlLoad(void);

asm void DWCi_HLlLoadSet(void)
{
	stmdb sp!, {r3, lr}
	bl DWCi_SETTIGNlGet
	ldrb r0, [r0, #0xf4]
	add r0, r0, #5
	bl DWCi_HLlLoad
	ldmia sp!, {r3, pc}
}

