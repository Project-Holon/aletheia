/*
 * function: KeyValHashKey
 * address:  0x0219DF54
 * packet:   pkt_ov009_0219DF54
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gsifree                      0x0217EAE0  arm
*/

extern void gsifree(void);
asm void KeyValHashKey(void)
{
	ldr r0, [r0]
	ldr ip, =gsifree
	bx ip
}

