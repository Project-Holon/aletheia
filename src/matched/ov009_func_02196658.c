/*
 * function: gti2IncomingBufferMessageCompare
 * address:  0x02196658
 * packet:   pkt_ov009_02196658
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gti2SNDiff                   0x02195EB4  arm
*/

extern void gti2SNDiff(void);

asm void gti2IncomingBufferMessageCompare(void)
{
	ldrh r0, [r0, #0xc]
	ldrh r1, [r1, #0xc]
	ldr ip, =gti2SNDiff
	bx ip
}

