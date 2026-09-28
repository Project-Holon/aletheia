/*
 * function: DWCi_HLlLoadList
 * address:  0x021BD6EC
 * packet:   pkt_ov016_021BD6EC
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

asm void DWCi_HLlLoadList(void)
{
	stmdb sp!, {r3, lr}
	bl DWCi_SETTIGNlGet
	ldrb r0, [r0, #0xf4]
	add r0, r0, #2
	bl DWCi_HLlLoad
	ldmia sp!, {r3, pc}
}

