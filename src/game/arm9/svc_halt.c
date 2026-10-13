/*
 * file:     svc_halt.c
 * function: SVC_Halt
 * address:  0x020040E2
 * packet:   pkt_020040E2
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

/* hand-written in the original: SVC_Halt, SVC stub in the arm9 secure area (swi 0x6; bx lr) */

asm void SVC_Halt(void)
{
    swi 0x6
    bx lr
}
