/*
 * function: endScene
 * address:  0x021C6A10
 * packet:   pkt_ov016_021C6A10
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_EFFlWait                0x021D5790  arm
 *   DWCi_ChangeScene             0x021C0E40  arm
*/

extern void DWCi_EFFlWait(void);
extern void DWCi_ChangeScene(void);

asm void endScene(void)
{
	stmdb sp!, {r3, lr}
	mov r0, #8
	bl DWCi_EFFlWait
	ldr r0, =0x021C6A2C
	bl DWCi_ChangeScene
	ldmia sp!, {r3, pc}
}

