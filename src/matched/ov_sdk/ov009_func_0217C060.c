/*
 * function: CameraStandbyCallback
 * address:  0x0217C060
 * packet:   pkt_ov009_0217C060
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWC_Free                     0x0205A1B0  arm
*/

extern void DWC_Free(void);
asm void CameraStandbyCallback(void)
{
	ldr ip, =DWC_Free
	mov r0, #0
	bx ip
}

