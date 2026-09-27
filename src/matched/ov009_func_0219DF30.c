/*
 * function: KeyValHashKey
 * address:  0x0219DF30
 * packet:   pkt_ov009_0219DF30
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   StringHash                   0x0219E848  arm
*/

extern void StringHash(void);
asm void KeyValHashKey(void)
{
	ldr r0, [r0]
	ldr ip, =StringHash
	bx ip
}

