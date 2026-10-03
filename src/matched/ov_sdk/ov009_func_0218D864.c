/*
 * function: CaseInsensitiveCompare
 * address:  0x0218D864
 * packet:   pkt_ov009_0218D864
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020948E0                0x020948E0  arm
*/

extern int func_020948E0(const char *s1, const char *s2);

asm void CaseInsensitiveCompare(void)
{
	ldr r0, [r0]
	ldr r1, [r1]
	ldr ip, =func_020948E0
	bx ip
}

