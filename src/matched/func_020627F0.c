/*
 * function: func_020627F0
 * address:  0x020627F0
 * packet:   pkt_020627F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm void *func_020627F0(void *ctx)
{
    ldrh r1, [r0, #2]
    tst r1, #1
    ldrh r1, [r0]
    ldrne r0, [r0, #4]
    addne r0, r0, r1, lsl #4
    ldreq r0, [r0, #4]
    addeq r0, r0, r1, lsl #3
    bx lr
}
