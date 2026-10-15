/*
 * function: NVRAMi_IsInitialized
 * address:  0x020841E8
 * packet:   pkt_020841E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   nvramBss 0x02150EA0 data
 */

extern void nvramBss(void);

asm void NVRAMi_IsInitialized(void)
{
    ldr r0, =nvramBss
    ldr	r0, [r0]
    cmp	r0, #2
    moveq	r0, #1
    movne	r0, #0
    bx	lr
}
