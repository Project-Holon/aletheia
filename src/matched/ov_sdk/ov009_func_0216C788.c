/*
 * function: DWCi_GT2ClosedCallback
 * address:  0x0216C788
 * packet:   pkt_ov009_0216C788
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_GT2ClosedProcess        0x0216C230  arm
*/

extern void DWCi_GT2ClosedProcess(void);

asm void DWCi_GT2ClosedCallback(void)
{
	ldr ip, =DWCi_GT2ClosedProcess
	mov r2, #0
	mov r3, #0xff
	bx ip
}

