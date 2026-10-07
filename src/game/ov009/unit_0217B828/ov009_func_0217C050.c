/*
 * function: CameraStandbyCallback
 * address:  0x0217C050
 * packet:   pkt_ov009_0217C050
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWC_Alloc                    0x0205A16C  arm
*/

extern void DWC_Alloc(void);
asm void CameraStandbyCallback(void)
{
	ldr ip, =DWC_Alloc
	mov r0, #0
	bx ip
}

