/*
 * function: SHA1_HMAC_GetHash
 * address:  0x02731764
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

asm void SHA1_HMAC_GetHash(void)
{
    mov     r12, r1
    add     r1, r0, #0
    mov     r0, r12
    swi     0x26
    bx      lr
    lsl     r0, r0, #0
}
