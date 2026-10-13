/*
 * file:     svc_wait_vblank_intr.c
 * function: SVC_WaitVBlankIntr
 * address:  0x020047A6
 * packet:   pkt_020047A6
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

/* hand-written in the original: SVC_WaitVBlankIntr, SVC stub in the arm9 secure area (swi 0x5; bx lr) */

asm void SVC_WaitVBlankIntr(void)
{
    swi 0x5
    bx lr
}
