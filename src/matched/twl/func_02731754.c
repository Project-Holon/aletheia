/*
 * function: SHA1_HMAC_Init
 * address:  0x02731754
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

asm void SHA1_HMAC_Init(void)
{
    mov     r3, #0x60
    add     r3, r0
    mov     r2, #0
    str     r2, [r3]
    swi     0x24
    bx      lr
}
