/*
 * function: get64bits
 * address:  0x021644B4
 * packet:   pkt_ov009_021644B4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   PENDING
 *
 * Hand-written SDK asm body: the object reads four unsigned short lanes with
 *   `ldrh`/`orr ...,lsl #16` and returns the pair in r0:r1. No C spelling of a
 *   64-bit load builds that shape -- `*(unsigned long long *)(s - 3)` compiles
 *   to two unaligned 32-bit loads (16 bytes: ldr r2,[r0,#-6]; ldr r1,[r0,#-2];
 *   mov r0,r2; bx lr) and the OR-based forms fail as get48bits_2 documents.
 *   Same family as the EXACT sibling get48bits_2 0x02164490 / get48bits_3
 *   0x021644A0, both already `asm void`.
 *
 * pending:  asm body kept as a reference only; the object has a C prototype (static u64 get64bits(u16 *s)), so an asm body is not evidence of a match. Needs a C spelling.
 * sdk:      get64bits (libssl.TWL.HYB.a biginteger.o)
 * symbols:
 */

asm void get64bits(void)
{
	ldrh r2, [r0]
	ldrh r3, [r0, #-2]
	orr r1, r3, r2, lsl #16
	ldrh r2, [r0, #-4]
	ldrh r3, [r0, #-6]
	orr r0, r3, r2, lsl #16
	bx lr
}
