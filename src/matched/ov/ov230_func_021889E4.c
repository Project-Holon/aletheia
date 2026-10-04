/*
 * function: func_021889E4
 * address:  0x021889E4
 * packet:   pkt_ov230_021889E4
 * region:   ov230
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     cache maintenance over [r0, r0 + r1): per 32-byte line it
 *           invalidates the I-cache line, drains the write buffer and cleans
 *           and invalidates the D-cache line. CP15 writes have no C
 *           spelling, so this is an asm function like DC_StoreRange.
 */

asm void func_021889E4(void *addr, unsigned int size)
{
    add     r1, r1, r0
    mov     ip, #0
    bic     r0, r0, #0x1f
loc_021889F0:
    mcr     p15, 0, r0, c7, c5, 1
    mcr     p15, 0, ip, c7, c10, 4
    mcr     p15, 0, r0, c7, c14, 1
    add     r0, r0, #0x20
    cmp     r0, r1
    blt     loc_021889F0
    bx      lr
}
