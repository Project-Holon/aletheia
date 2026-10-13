/*
 * file:     svc_get_crc16.c
 * function: SVC_GetCRC16
 * address:  0x02004632
 * packet:   pkt_02004490
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     wave 16: the CCERR of 2026-09-20 no longer reproduces; EXACT* (the
 *           listing extent runs over the data that follows this 4-byte SVC
 *           stub).  A Thumb `asm` function: swi, then return.
 */

/* hand-written in the original: SVC_GetCRC16, SVC stub in the arm9 secure area (swi 0xe; bx lr) */
asm void SVC_GetCRC16(void)
{
    swi 0xe
    bx lr
}
