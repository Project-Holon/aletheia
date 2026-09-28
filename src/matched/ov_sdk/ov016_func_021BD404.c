/*
 * function: DWCi_FOCUSlEnd
 * address:  0x021BD404
 * packet:   pkt_ov016_021BD404
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_FOCUSlDelete            0x021BD5A8  arm
 *   DWCi_HEAPlFree_              0x021D6438  arm
*/

extern void DWCi_FOCUSlDelete(void);
extern void DWCi_HEAPlFree_(void);

asm void DWCi_FOCUSlEnd(void)
{
	stmdb sp!, {r3, lr}
	bl DWCi_FOCUSlDelete
	ldr r0, =0x021DE550
	bl DWCi_HEAPlFree_
	ldmia sp!, {r3, pc}
}

